#pragma once
#include "KamataEngine.h"
#include "particle.h"
#include "Model2.h"
using namespace KamataEngine;
class GameScene {
public:
	//初期化
	void Initialize();

	//更新
	void Update();

	//描画
	void Draw();

	//パーティクル3Dモデルデータ
	Model2* modelParticle_ = nullptr;

	//カメラ
	Camera camera_;

	//パーティクル
	particle* particle_ = nullptr;

	//デストラクタ
	~GameScene();
};
