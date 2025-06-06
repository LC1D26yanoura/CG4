#include "GameScene.h"
#include<random>
std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);
using namespace KamataEngine;

void GameScene::Initialize() {

    //3Dモデルデータの生成
	modelParticle_ = Model::CreateSphere(4, 4);

	modelEffect_ = Model::CreateSphere(2, 2);

	//カメラの生成
	camera_.Initialize();

	

	//乱数の初期化
	srand((unsigned)time(NULL));
}

void GameScene::Update() {

	// パーティクルの更新
	for (Particle* particle : particles_) {
		particle->Update();
	};

	particles_.remove_if([] ( Particle * particle) {
		if (particle->isFinished() == true) {
			delete particle;
			return true;
		}
		return false;
	});

	//確率で発生
	if (rand() % 20 == 0) {

	Vector3 position = {distribution(randomEngine) * 30.0f, distribution(randomEngine) * 20.0f, 0};
	particleBorn(position);
	
	}


	effects_.remove_if([](Effect* effect) {
		if (effect->isFinished() == true) {
			delete effect;
			return true;
		}
		return false;
	});

	// 確率で発生
	if (rand() % 20 == 0) {

		Vector3 position = {distribution(randomEngine) * 30.0f, distribution(randomEngine) * 20.0f, 0};
		effectBorn(position);
	}
	// エフェクトの更新
	for (Effect* effect : effects_) {
		effect->Update();
	};
}

void GameScene::Draw() {

	// DirectXCommonインスタンスの取得
	DirectXCommon* dxcommon = DirectXCommon::GetInstance();

	// 3Dモデル描画前処理
	Model::PreDraw(dxcommon->GetCommandList());


    //パーティクルの描画
	/*for (Particle* particle : particles_) {
		particle->Draw(camera_);
	}*/

	//エフェクトの描画
	for (Effect* effect : effects_) {
		effect->Draw(camera_);
	}
	// 3Dモデル描画後処理
	Model::PostDraw();
}


void GameScene::particleBorn(Vector3 position) {
	//パーティクルの生成
	//particle_ = new particle();
	for (int i = 0; i < 150; i++) {
		// 生成
		Particle* particle = new Particle();
	// 位置
	//Vector3 position = {0.0f, 0.0f, 0.0f};
	//移動量
	Vector3 velocity = {distribution(randomEngine), distribution(randomEngine), 0};
	//初期化
	particle->Initialize(modelParticle_,position,velocity);
	//リストに追加
	particles_.push_back(particle);
	}
	}

void GameScene::effectBorn(KamataEngine::Vector3 position) {

	    for (int i = 0; i < 10; i++) {
		    // 生成
		    Effect* effect = new Effect();
		    // 位置
		    // Vector3 position = {0.0f, 0.0f, 0.0f};
		    // 移動量
		    //Vector3 velocity = {distribution(randomEngine), distribution(randomEngine), 0};
			
			Vector3 scale = {1.0f, distribution(randomEngine) * 10, 1.0f};

			Vector3 rotate = {1.0f, distribution(randomEngine) * 10, 1.0f};

		    // 初期化
		    effect->Initialize(modelEffect_, position, scale, rotate);
		    // リストに追加
		    effects_.push_back(effect);
	    }
    }

	    GameScene::~GameScene() {

		    delete modelParticle_;
		    delete modelEffect_;
		    for (Particle* particle : particles_) {
			    delete particle;
		    }
		    for (Effect* effect : effects_) {
			    delete effect;
		    }
	    }
   
