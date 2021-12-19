#pragma once

enum class CameraShakeType 
{
	None = 0,
	HandShake,
	SmallExplosionShake,
	MediumExplosionShake,
	LargeExplosionShake,
	JoltExplosionShake,
	VibrateExplosionShake,
	WobblyExplosionShake,
	DrunkExplosionShake,
};

class GameCamera
{
private:
	Cam _handle;

public:
	static GameCamera getRenderingCam();
	static GameCamera* defaultCamera();
	static void setScriptCamsRendering(bool shouldRender, bool withEase = true, int easeTimeMillis = 3000);

	GameCamera(Cam handle);
	GameCamera(Vector3 position);
	GameCamera(Vector3 position, float fov);
	GameCamera(Vector3 position, Vector3 rotation);
	GameCamera(Vector3 position, Vector3 rotation, float fov);

	Vector3 getPosition();
	void setPosition(Vector3 position);
	Vector3 getRotation();
	void setRotation(Vector3 setRotation);
	bool getIsActive();
	void setIsActive(bool isActive);
	float getFov();
	void setFov(float fov);
	void pointAt(Vector3 coord);
	void pointAt(Entity entity);
	void pointAt(Entity, Vector3 offset);
	void stopPointing();
	void shake(CameraShakeType shakeType, float amplitude);
	void stopShaking();
	bool isShaking();
	void attachTo(Entity entity, Vector3 offset, bool isRelative = true);
	void detach();
	void destroy();
};