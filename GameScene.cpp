#include "GameScene.h"
#include<random>
std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);
using namespace KamataEngine;

void GameScene::Initialize() {

    //3Dモデルデータの生成
	modelParticle_ = Model::CreateSphere(4, 4);

	//カメラの生成
	camera_.Initialize();

	//パーティクルの生成
	//particle_ = new particle();
	for (int i = 0; i < 150; i++) {
	//生成
	Particle* particle = new Particle();
	// 位置
	Vector3 position = {0.0f, 0.0f, 0.0f};
	//移動量
	Vector3 velocity = {distribution(randomEngine), distribution(randomEngine), 0};
	//初期化
	particle->Initialize(modelParticle_,position,velocity);
	//リストに追加
	particles_.push_back(particle);
	}
	
}

void GameScene::Update() {

	// パーティクルの更新
	for (Particle* particle : particles_) {
	particle->Update();
	}

}

void GameScene::Draw() {

	// DirectXCommonインスタンスの取得
	DirectXCommon* dxcommon = DirectXCommon::GetInstance();

	// 3Dモデル描画前処理
	Model::PreDraw(dxcommon->GetCommandList());


    //パーティクルの描画
	for (Particle* particle : particles_) {
		particle->Draw(camera_);
	}
	// 3Dモデル描画後処理
	Model::PostDraw();
}

GameScene::~GameScene() {

	delete modelParticle_;
	for (Particle* particle : particles_) {
		delete particle;
	}
}
