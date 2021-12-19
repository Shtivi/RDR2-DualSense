#include "Main.h"

Propset::Propset(int handle)
{
	this->handle = handle;
}

Propset Propset::spawn(Vector3 location, const char* model)
{
	int propsetHash = MISC::GET_HASH_KEY((char*)model);
	PROPSET::_REQUEST_PROP_SET(propsetHash);

	int i = 0;
	while (!PROPSET::_HAS_PROP_SET_LOADED(propsetHash) && i < 100)
	{
		i++;
		PROPSET::_REQUEST_PROP_SET(propsetHash);
		WAIT(20);
	}

	Propset propset(0);
	if (PROPSET::_HAS_PROP_SET_LOADED(propsetHash))
	{
		propset.handle = PROPSET::_CREATE_PROP_SET_2(propsetHash, location.x, location.y, location.z, 0, 60, 1200, false, true);
	}

	PROPSET::_RELEASE_PROP_SET(propsetHash);
	return propset;
}