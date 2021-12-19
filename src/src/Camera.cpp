#include "Main.h";

static GameCamera* _default;

const char* const CAM_SHAKING_NAMES[] = {
	"NONE", "HAND_SHAKE", "SMALL_EXPLOSION_SHAKE", "MEDIUM_EXPLOSION_SHAKE",
	"LARGE_EXPLOSION_SHAKE", "JOLT_SHAKE", "VIBRATE_SHAKE", "WOBBLY_SHAKE", "DRUNK_SHAKE"
};

GameCamera GameCamera::getRenderingCam()
{
	return GameCamera(CAM::GET_RENDERING_CAM());
}

GameCamera* GameCamera::defaultCamera()
{
	if (!_default)
	{
		Vector3 offset = getForwardVector(player) * -3 + getUpVector(player) * -0.3 + getRightVector(player) * 0.5f;
		_default = new GameCamera(entityPos(player), 60);
		_default->attachTo(player, offset);
	}

	return _default;
}

void GameCamera::setScriptCamsRendering(bool shouldRender, bool ease, int easeTimeMillis)
{
	CAM::RENDER_SCRIPT_CAMS(shouldRender, ease, easeTimeMillis, 1, 0, 0);
}

GameCamera::GameCamera(Cam handle)
{
	_handle = handle;
}

GameCamera::GameCamera(Vector3 position)
	: GameCamera(position, toVector3(0,0,0))
{
}

GameCamera::GameCamera(Vector3 position, float fov)
	: GameCamera(position, toVector3(0,0,0), fov)
{
}

GameCamera::GameCamera(Vector3 position, Vector3 rotation)
	: GameCamera(position, rotation, 0)
{
}

GameCamera::GameCamera(Vector3 position, Vector3 rotation, float fov)
	: GameCamera(CAM::CREATE_CAM_WITH_PARAMS(
		"DEFAULT_SCRIPTED_CAMERA", position.x, position.y, position.z, rotation.x, rotation.y, rotation.z, fov, 1, 2))
{
}

Vector3 GameCamera::getPosition()
{
	return CAM::GET_CAM_COORD(_handle);
}

void GameCamera::setPosition(Vector3 position)
{
	CAM::SET_CAM_COORD(_handle, position.x, position.y, position.z);
}

Vector3 GameCamera::getRotation()
{
	CAM::GET_CAM_ROT(_handle, 2);
}

void GameCamera::setRotation(Vector3 rotation)
{
	CAM::SET_CAM_ROT(_handle, rotation.x, rotation.y, rotation.z, 2);
}

bool GameCamera::getIsActive()
{
	return CAM::IS_CAM_ACTIVE(_handle);
}

void GameCamera::setIsActive(bool isActive)
{
	CAM::SET_CAM_ACTIVE(_handle, isActive);
}

float GameCamera::getFov()
{
	return CAM::GET_CAM_FOV(_handle);
}

void GameCamera::setFov(float fov)
{
	return CAM::SET_CAM_FOV(_handle, fov);
}

void GameCamera::pointAt(Vector3 position)
{
	CAM::POINT_CAM_AT_COORD(_handle, position.x, position.y, position.z);
}

void GameCamera::pointAt(Entity entity)
{
	pointAt(entity, toVector3(0, 0, 0));
}

void GameCamera::pointAt(Entity entity, Vector3 offset)
{
	CAM::POINT_CAM_AT_ENTITY(_handle, entity, offset.x, offset.y, offset.z, true);
}

void GameCamera::stopPointing()
{
	CAM::STOP_CAM_POINTING(_handle);
}

void GameCamera::shake(CameraShakeType shakeType, float amplitude)
{
	CAM::SHAKE_CAM(_handle, (char*)CAM_SHAKING_NAMES[(int)shakeType], amplitude);
}

void GameCamera::stopShaking()
{
	CAM::STOP_CAM_SHAKING(_handle, true);
}

bool GameCamera::isShaking()
{
	return CAM::IS_CAM_SHAKING(_handle);
}

void GameCamera::attachTo(Entity entity, Vector3 offset, bool isRelative)
{
	CAM::ATTACH_CAM_TO_ENTITY(_handle, entity, offset.x, offset.y, offset.z, isRelative);
}

void GameCamera::detach()
{
	CAM::DETACH_CAM(_handle);
}

void GameCamera::destroy()
{
	setIsActive(false);
	stopPointing();
	CAM::DESTROY_CAM(_handle, false);
}