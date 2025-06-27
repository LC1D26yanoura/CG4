#pragma once
#include<KamataEngine.h>
#include <cassert>
#include"Model2.h"
using namespace KamataEngine;
class particle {
public:
	// 初期化
	void Initialize(Model2*model);

	// 更新
	void Update();

	// 描画
	void Draw(Camera&camera);

private:
	//ワールド変換データ
	WorldTransform worldTransform_;

	//モデル
	Model2* model_ = nullptr;

};
