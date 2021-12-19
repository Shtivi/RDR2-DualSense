#pragma once

class Rope
{
public:
	virtual Entity getBase() = 0;
	virtual Entity getAttached() = 0;
	virtual bool isExist() = 0;
	virtual bool canWind() = 0;
	virtual void startWinding() = 0;
	virtual void stopWinding() = 0;
	virtual bool canUnwind() = 0;
	virtual void startUnwinding() = 0;
	virtual void stopUnwinding() = 0;
	virtual void detach() = 0;
	virtual int update() = 0;
};


#include "AttachedRope.h";
#include "MultiVertexRope.h";
#include "AttachedRopesHanding.h"