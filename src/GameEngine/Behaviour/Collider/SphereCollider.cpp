// SphereCollider.cpp

#include "SphereCollider.h"

#include "../Transform.h"


namespace GameEngine { namespace Behaviour
{
// 中心座標と半径を取得
SphereCollider::SphereCollider(D3DXVECTOR3 center, float radius) :Collider()
{
	_center = center;
	_radius = radius;
}

SphereCollider::~SphereCollider()
{
}

float* SphereCollider::GetRadius()
{
	return &_radius;
}

void SphereCollider::Hit()
{
	//イテレーターを使ったループ vectorを使ったときは基本こっち
	for (auto iterator = _colliders.begin(); iterator != _colliders.end(); ++iterator)
	{
		if (*iterator == this) continue;//自分は除く
		SphereCollider *sphere = dynamic_cast<SphereCollider*>(*iterator);//動的にキャスト、もしCircleColliderじゃなかったらNULL(nullptr)が帰ってくる
		if (sphere)
		{
			this->HitToSphere(sphere);
			continue;
		}

		BoxCollider *box = dynamic_cast<BoxCollider*>(*iterator);//動的にキャスト、もしCircleColliderじゃなかったらNULL(nullptr)が帰ってくる
		if (box)
		{
			this->HitToBox(box);
			continue;
		}
	}
}

void SphereCollider::HitToSphere(SphereCollider* collider)
{
	GameObject* me;			// 自分側のゲームオブジェクト
	GameObject* other;		// 相手側オブジェクト
	float range;			// 当たり判定の範囲
	float magnitude;		// 自分から相手までの距離の二乗
	D3DXVECTOR3 mePos, otherPos;	// 自分と相手の位置
	mePos = this->_center;
	otherPos = collider->GetAttachedObject()->GetTransform()->GetPosition;
	range = _radius + collider->_radius;	// 判定の範囲を取得

	magnitude = (mePos.x - otherPos.x)*(mePos.x - otherPos.x) + (mePos.y - otherPos.y)*(mePos.y - otherPos.y) + (mePos.z - otherPos.z)*(mePos.z - otherPos.z);
	if (magnitude <= range*range)
	{
		// 当たった
	}

}

void SphereCollider::HitToBox(BoxCollider* collider)
{
	GameObject* me;			// 自分側のゲームオブジェクト
	GameObject* other;		// 相手側オブジェクト
	float range;			// 当たり判定の範囲
	float magnitude;		// 自分から相手までの距離の二乗
	D3DXVECTOR3 mePos, otherPos[8];	// 自分と相手(頂点配列)の位置
	D3DXVECTOR3* otherScale;	// 相手の大きさ

	mePos = this->_center;
	for (int i = 0; i < 8; i++)
		otherPos[i] = collider->GetAttachedObject()->GetTransform()->GetPosition;// ８つに中心座標の格納

	otherScale = collider->GetScale();// 相手の大きさの格納

	// 直方体の上の頂点（左下から時計回り）
	otherPos[0].x -= otherScale->x / 2.0f;
	otherPos[0].y += otherScale->y / 2.0f;
	otherPos[0].z -= otherScale->z / 2.0f;
	otherPos[1].x -= otherScale->x / 2.0f;
	otherPos[1].y += otherScale->y / 2.0f;
	otherPos[1].z += otherScale->z / 2.0f;
	otherPos[2].x += otherScale->x / 2.0f;
	otherPos[2].y += otherScale->y / 2.0f;
	otherPos[2].z += otherScale->z / 2.0f;
	otherPos[3].x += otherScale->x / 2.0f;
	otherPos[3].y += otherScale->y / 2.0f;
	otherPos[3].z -= otherScale->z / 2.0f;
	// 直方体の下の頂点（左下から時計回り）
	otherPos[4].x -= otherScale->x / 2.0f;
	otherPos[4].y -= otherScale->y / 2.0f;
	otherPos[4].z -= otherScale->z / 2.0f;
	otherPos[5].x -= otherScale->x / 2.0f;
	otherPos[5].y -= otherScale->y / 2.0f;
	otherPos[5].z += otherScale->z / 2.0f;
	otherPos[6].x += otherScale->x / 2.0f;
	otherPos[6].y -= otherScale->y / 2.0f;
	otherPos[6].z += otherScale->z / 2.0f;
	otherPos[7].x += otherScale->x / 2.0f;
	otherPos[7].y -= otherScale->y / 2.0f;
	otherPos[7].z -= otherScale->z / 2.0f;
			 
	range = _radius + 0.0f;			// 判定の範囲を取得 頂点なので半径0.0f

	for (int i = 0; i < 8; i++)
	{
		magnitude = (mePos.x - otherPos[i].x)*(mePos.x - otherPos[i].x) + (mePos.y - otherPos[i].y)*(mePos.y - otherPos[i].y) + (mePos.z - otherPos[i].z)*(mePos.z - otherPos[i].z);
		if (magnitude <= range*range)
		{
			// 直方体の８つの頂点のいずれかに当たった
		}
	}

	D3DXVECTOR3 otherPosSurface[24];
	//上の面
	otherPosSurface[0] = otherPos[0];
	otherPosSurface[1] = otherPos[1];
	otherPosSurface[2] = otherPos[2];
	otherPosSurface[3] = otherPos[3];
	// 正面の面
	otherPosSurface[4] = otherPos[4];
	otherPosSurface[5] = otherPos[0];
	otherPosSurface[6] = otherPos[3];
	otherPosSurface[7] = otherPos[7];
	// 左の面
	otherPosSurface[8] = otherPos[5];
	otherPosSurface[9] = otherPos[1];
	otherPosSurface[10] = otherPos[0];
	otherPosSurface[11] = otherPos[4];
	// 後ろの面
	otherPosSurface[12] = otherPos[5];
	otherPosSurface[13] = otherPos[1];
	otherPosSurface[14] = otherPos[2];
	otherPosSurface[15] = otherPos[6];
	// 右の面
	otherPosSurface[16] = otherPos[7];
	otherPosSurface[17] = otherPos[3];
	otherPosSurface[18] = otherPos[2];
	otherPosSurface[19] = otherPos[6];
	// 下の面
	otherPosSurface[20] = otherPos[4];
	otherPosSurface[21] = otherPos[5];
	otherPosSurface[22] = otherPos[6];
	otherPosSurface[23] = otherPos[7];

	//for (int i = 0; i < 6; i++)
	//{
	//	if (otherPosSurface[i + (i * 4)] < mePos && otherPosSurface[i + 1 + (i * 4)] > mePos && otherPosSurface[i + 1 + (i * 4)] < mePos && otherPosSurface[i + 2 + (i * 4)] > mePos && otherPosSurface[i + 2 + (i * 4)] > mePos && otherPosSurface[i + 3 + (i * 4)] < mePos && otherPosSurface[i + 3 + (i * 4)] > mePos && otherPosSurface[i + (i * 4)] < mePos)
	//	{
	//		// 上の面、正面の面、左の面、後ろの面、右の面、下の面いずれかに当たった
	//	}
	//}

	if (otherPosSurface[0].z <= mePos.z && otherPosSurface[1].z >= mePos.z && otherPosSurface[1].x <= mePos.x && otherPosSurface[2].x >= mePos.x && otherPosSurface[2].z >= mePos.z && otherPosSurface[3].z <= mePos.z && otherPosSurface[3].x >= mePos.x && otherPosSurface[0].x <= mePos.x && (otherPosSurface[0].y <= mePos.y + _radius || otherPosSurface[0].y >= mePos.y + _radius))
	{
		// 上面に当たった
	}
	else if (otherPosSurface[4].y <= mePos.y && otherPosSurface[5].y >= mePos.y && otherPosSurface[5].x <= mePos.x && otherPosSurface[6].x >= mePos.x && otherPosSurface[6].y >= mePos.y && otherPosSurface[7].y <= mePos.y && otherPosSurface[7].x >= mePos.x && otherPosSurface[4].x <= mePos.x && (otherPosSurface[4].z <= mePos.z + _radius || otherPosSurface[4].z >= mePos.z + _radius))
	{
		// 正面の面に当たった
	}
	else if (otherPosSurface[8].y <= mePos.y && otherPosSurface[9].y >= mePos.y && otherPosSurface[9].z <= mePos.z && otherPosSurface[10].z >= mePos.z && otherPosSurface[10].y >= mePos.y && otherPosSurface[11].y <= mePos.y && otherPosSurface[11].z >= mePos.z && otherPosSurface[8].z <= mePos.z && (otherPosSurface[8].x <= mePos.x + _radius || otherPosSurface[8].x >= mePos.x + _radius))
	{
		// 左の面に当たった
	}
	else if (otherPosSurface[12].y <= mePos.y && otherPosSurface[13].y >= mePos.y && otherPosSurface[13].x <= mePos.x && otherPosSurface[14].x >= mePos.x && otherPosSurface[14].y >= mePos.y && otherPosSurface[15].y <= mePos.y && otherPosSurface[15].x >= mePos.x && otherPosSurface[12].x <= mePos.x && (otherPosSurface[12].z <= mePos.z + _radius || otherPosSurface[12].z >= mePos.z + _radius))
	{
		// 後ろの面に当たった
	}
	else if (otherPosSurface[16].y <= mePos.y && otherPosSurface[17].y >= mePos.y && otherPosSurface[17].z <= mePos.z && otherPosSurface[18].z >= mePos.z && otherPosSurface[18].y >= mePos.y && otherPosSurface[19].y <= mePos.y && otherPosSurface[19].z >= mePos.z && otherPosSurface[16].z <= mePos.z && (otherPosSurface[16].x <= mePos.x + _radius || otherPosSurface[16].x >= mePos.x + _radius))
	{
		// 右の面に当たった
	}
	else if (otherPosSurface[20].z <= mePos.z && otherPosSurface[21].z >= mePos.z && otherPosSurface[21].x <= mePos.x && otherPosSurface[22].x >= mePos.x && otherPosSurface[22].z >= mePos.z && otherPosSurface[23].z <= mePos.z && otherPosSurface[23].x >= mePos.x && otherPosSurface[20].x <= mePos.x && (otherPosSurface[20].y <= mePos.y + _radius || otherPosSurface[20].y >= mePos.y + _radius))
	{
		// 底面に当たった
	}

}


}
}