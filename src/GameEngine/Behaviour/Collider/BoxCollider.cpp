// BoxCollider.cpp

#include "BoxCollider.h"

#include "../Transform.h"

namespace GameEngine { namespace Behaviour
{
// 中心座標と大きさを取得
BoxCollider::BoxCollider(D3DXVECTOR3 position, D3DXVECTOR3 scale) :Collider()
{
	_position = position;
	_scale = scale;
}

BoxCollider::~BoxCollider()
{
}

D3DXVECTOR3* BoxCollider::GetScale()
{
	return &_scale;
}

void BoxCollider::Hit()
{
	//イテレーターを使ったループ vectorを使ったときは基本こっち
	for (auto iterator = _colliders.begin(); iterator != _colliders.end(); ++iterator)
	{
		if (*iterator == this) continue;//自分は除く
		BoxCollider *box = dynamic_cast<BoxCollider*>(*iterator);// 動的にキャスト、もしBoxColliderじゃなかったらNULL(nullptr)が帰ってくる
		if (box)
		{
			this->HitToBox(box);
			continue;
		}

		SphereCollider *sphere = dynamic_cast<SphereCollider*>(*iterator);// 動的にキャスト、もしSphereColliderじゃなかったらNULL(nullptr)が帰ってくる
		if (box)
		{
			this->HitToSphere(sphere);
			continue;
		}
	}
}

void BoxCollider::HitToSphere(SphereCollider* collider)
{
	float range;			// 当たり判定の範囲
	float magnitude;		// 自分から相手までの距離の二乗
	D3DXVECTOR3 mePos[8], otherPos;	// 自分と相手(頂点配列)の位置
	D3DXVECTOR3 meScale;	// 自分の大きさ
	float* otherRadius;		// 相手の球の半径

	
	for (int i = 0; i < 8; i++)
		mePos[i] = this->_position;// ８つに直方体の中心座標を格納
	meScale = this->_scale;
	otherPos = collider->GetAttachedObject()->GetTransform()->GetPosition();
	otherRadius = collider->GetRadius();

																		 // 直方体の上の頂点（左下から時計回り）
	mePos[0].x -= meScale.x / 2.0f;
	mePos[0].y += meScale.y / 2.0f;
	mePos[0].z -= meScale.z / 2.0f;
	mePos[1].x -= meScale.x / 2.0f;
	mePos[1].y += meScale.y / 2.0f;
	mePos[1].z += meScale.z / 2.0f;
	mePos[2].x += meScale.x / 2.0f;
	mePos[2].y += meScale.y / 2.0f;
	mePos[2].z += meScale.z / 2.0f;
	mePos[3].x += meScale.x / 2.0f;
	mePos[3].y += meScale.y / 2.0f;
	mePos[3].z -= meScale.z / 2.0f;
	// 直方体の下の頂点（左下から時計回り）
	mePos[4].x -= meScale.x / 2.0f;
	mePos[4].y -= meScale.y / 2.0f;
	mePos[4].z -= meScale.z / 2.0f;
	mePos[5].x -= meScale.x / 2.0f;
	mePos[5].y -= meScale.y / 2.0f;
	mePos[5].z += meScale.z / 2.0f;
	mePos[6].x += meScale.x / 2.0f;
	mePos[6].y -= meScale.y / 2.0f;
	mePos[6].z += meScale.z / 2.0f;
	mePos[7].x += meScale.x / 2.0f;
	mePos[7].y -= meScale.y / 2.0f;
	mePos[7].z -= meScale.z / 2.0f;

	range = 0.0f + *otherRadius;			// 判定の範囲を取得 頂点なので半径0.0f

	for (int i = 0; i < 8; i++)
	{
		magnitude = (mePos[i].x - otherPos.x)*(mePos[i].x - otherPos.x) + (mePos[i].y - otherPos.y)*(mePos[i].y - otherPos.y) + (mePos[i].z - otherPos.z)*(mePos[i].z - otherPos.z);
		if (magnitude <= range*range)
		{
			// 直方体の８つの頂点のいずれかに当たった
		}
	}

	D3DXVECTOR3 mePosSurface[24];		// ４つで１つの面になる
	//上の面
	mePosSurface[0] = mePos[0];
	mePosSurface[1] = mePos[1];
	mePosSurface[2] = mePos[2];
	mePosSurface[3] = mePos[3];
	// 正面の面		  
	mePosSurface[4] = mePos[4];
	mePosSurface[5] = mePos[0];
	mePosSurface[6] = mePos[3];
	mePosSurface[7] = mePos[7];
	// 左の面		   
	mePosSurface[8] = mePos[5];
	mePosSurface[9] = mePos[1];
	mePosSurface[10] = mePos[0];
	mePosSurface[11] = mePos[4];
	// 後ろの面		   
	mePosSurface[12] = mePos[5];
	mePosSurface[13] = mePos[1];
	mePosSurface[14] = mePos[2];
	mePosSurface[15] = mePos[6];
	// 右の面			
	mePosSurface[16] = mePos[7];
	mePosSurface[17] = mePos[3];
	mePosSurface[18] = mePos[2];
	mePosSurface[19] = mePos[6];
	// 下の面			
	mePosSurface[20] = mePos[4];
	mePosSurface[21] = mePos[5];
	mePosSurface[22] = mePos[6];
	mePosSurface[23] = mePos[7];

	if (mePosSurface[0].z <= otherPos.z && mePosSurface[1].z >= otherPos.z && mePosSurface[1].x <= otherPos.x && mePosSurface[2].x >= otherPos.x && mePosSurface[2].z >= otherPos.z && mePosSurface[3].z <= otherPos.z && mePosSurface[3].x >= otherPos.x && mePosSurface[0].x <= otherPos.x && (mePosSurface[0].y <= otherPos.y + *otherRadius || mePosSurface[0].y >= otherPos.y + *otherRadius))
	{
		// 上面に当たった
	}
	else if (mePosSurface[4].y <= otherPos.y && mePosSurface[5].y >= otherPos.y && mePosSurface[5].x <= otherPos.x && mePosSurface[6].x >= otherPos.x && mePosSurface[6].y >= otherPos.y && mePosSurface[7].y <= otherPos.y && mePosSurface[7].x >= otherPos.x && mePosSurface[4].x <= otherPos.x && (mePosSurface[4].z <= otherPos.z + *otherRadius || mePosSurface[4].z >= otherPos.z + *otherRadius))
	{
		// 正面の面に当たった
	}
	else if (mePosSurface[8].y <= otherPos.y && mePosSurface[9].y >= otherPos.y && mePosSurface[9].z <= otherPos.z && mePosSurface[10].z >= otherPos.z && mePosSurface[10].y >= otherPos.y && mePosSurface[11].y <= otherPos.y && mePosSurface[11].z >= otherPos.z && mePosSurface[8].z <= otherPos.z && (mePosSurface[8].x <= otherPos.x + *otherRadius || mePosSurface[8].x >= otherPos.x + *otherRadius))
	{
		// 左の面に当たった
	}
	else if (mePosSurface[12].y <= otherPos.y && mePosSurface[13].y >= otherPos.y && mePosSurface[13].x <= otherPos.x && mePosSurface[14].x >= otherPos.x && mePosSurface[14].y >= otherPos.y && mePosSurface[15].y <= otherPos.y && mePosSurface[15].x >= otherPos.x && mePosSurface[12].x <= otherPos.x && (mePosSurface[12].z <= otherPos.z + *otherRadius || mePosSurface[12].z >= otherPos.z + *otherRadius))
	{
		// 後ろの面に当たった
	}
	else if (mePosSurface[16].y <= otherPos.y && mePosSurface[17].y >= otherPos.y && mePosSurface[17].z <= otherPos.z && mePosSurface[18].z >= otherPos.z && mePosSurface[18].y >= otherPos.y && mePosSurface[19].y <= otherPos.y && mePosSurface[19].z >= otherPos.z && mePosSurface[16].z <= otherPos.z && (mePosSurface[16].x <= otherPos.x + *otherRadius || mePosSurface[16].x >= otherPos.x + *otherRadius))
	{
		// 右の面に当たった
	}
	else if (mePosSurface[20].z <= otherPos.z && mePosSurface[21].z >= otherPos.z && mePosSurface[21].x <= otherPos.x && mePosSurface[22].x >= otherPos.x && mePosSurface[22].z >= otherPos.z && mePosSurface[23].z <= otherPos.z && mePosSurface[23].x >= otherPos.x && mePosSurface[20].x <= otherPos.x && (mePosSurface[20].y <= otherPos.y + *otherRadius || mePosSurface[20].y >= otherPos.y + *otherRadius))
	{
		// 底面に当たった
	}
}

void BoxCollider::HitToBox(BoxCollider* collider)
{

}


}
}