#include "particle.h"
using namespace MathUtility;
void particle::Initialize(Model*model) {
	//nullポインタチェック
	assert(model);

	model_ = model;

	worldTransform_.Initialize();

	//色の設定
	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};
}

void particle::Update() {

	//移動
	worldTransform_.translation_ += {0.0f, 0.1f, 0.0f};
		
	//行列を更新
	worldTransform_.UpdateMatrix();

	//色変更オブジェクトに色の数値を設定する
	objectColor_.SetColor(color_);
}

void particle::Draw(Camera& camera) {

	//3Dモデルを描画
	model_->Draw(worldTransform_, camera, &objectColor_);


}
