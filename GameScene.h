#pragma once
#include "KamataEngine.h"
#include "particle.h"

class GameScene {
public:
	//初期化
	void Initialize();

	//更新
	void Update();

	//描画
	void Draw();

	//パーティクル3Dモデルデータ
	KamataEngine::Model* modelParticle_ = nullptr;

	//カメラ
	KamataEngine::Camera camera_;

	//パーティクル
	//particle* particle_ = nullptr;
	std::list<Particle*> particles_;

	void particleBorn(KamataEngine::Vector3 position);

	//デストラクタ
	~GameScene();
};
