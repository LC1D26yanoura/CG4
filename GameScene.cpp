#include "GameScene.h"
using namespace KamataEngine;

void GameScene::Initialize() {
	Model2::StaticInitialize();

    //3Dモデルデータの生成
	modelParticle_ = Model2::CreateSquare();

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
	Model2::PreDraw(dxcommon->GetCommandList());


    //パーティクルの描画
	particle_->Draw(camera_);

	// 3Dモデル描画後処理
	Model2::PostDraw();
}

GameScene::~GameScene() {

	delete modelParticle_;
	delete particle_;
	Model2::StaticFinalize();

}
