#include "Effect.h"
using namespace KamataEngine::MathUtility;
using namespace KamataEngine;
void Effect::Initialize(Model* model, Vector3 position,Vector3 scale,Vector3 rotate) {
	// nullポインタチェック
	assert(model);

	model_ = model;

	worldTransform_.Initialize();

	worldTransform_.translation_ = position;

	worldTransform_.scale_ = scale;

    worldTransform_.rotation_ = rotate;

	//velocity_ = velocity;

	// 色の設定
	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};
}

void Effect::Update() {

	// 移動
	//worldTransform_.translation_ += velocity_;

	// 行列を更新
	worldTransform_.UpdateMatrix();

	// 色変更オブジェクトに色の数値を設定する
	objectColor_.SetColor(color_);
	
	// 終了なら何もしない
	if (isFinished_) {
		return;
	}
	// カウンターを１フレーム分の秒数進める
	counter_ += 1.0f / 60.0f;
	// 存続時間の上限に達したら
	if (counter_ >= kDuration) {
		counter_ = kDuration;
	// 終了扱いにする
		isFinished_ = true;
	}

	// フェード処理
	color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f);
}

void Effect::Draw(Camera& camera) {

	// 3Dモデルを描画
	model_->Draw(worldTransform_, camera,&objectColor_);
}
