#include "particle.h"

void particle::Initialize(Model2*model) {
	//nullポインタチェック
	assert(model);
	
	model_ = model;

	worldTransform_.Initialize();
}

void particle::Update() {

//行列を定数バッファに転送
	worldTransform_.TransferMatrix();

}

void particle::Draw(Camera& camera) {

	//3Dモデルを描画
	model_->Draw(worldTransform_, camera);

}
