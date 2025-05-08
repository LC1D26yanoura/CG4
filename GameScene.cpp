#include "GameScene.h"
using namespace KamataEngine;

void GameScene::Initialize() {

    //3Dモデルデータの生成
	modelParticle_ = Model::CreateSphere(4, 4);

	//カメラの生成
	camera_.Initialize();

	//パーティクルの生成
	particle_ = new particle();
	//パーティクルの初期化
	particle_->Initialize(modelParticle_);
}

void GameScene::Update() {

	// パーティクルの更新
	particle_->Update();

}

void GameScene::Draw() {

	// DirectXCommonインスタンスの取得
	DirectXCommon* dxcommon = DirectXCommon::GetInstance();

	// 3Dモデル描画前処理
	Model::PreDraw(dxcommon->GetCommandList());


    //パーティクルの描画
	particle_->Draw(camera_);

	// 3Dモデル描画後処理
	Model::PostDraw();
}

GameScene::~GameScene() {

	delete modelParticle_;
	delete particle_;

}
