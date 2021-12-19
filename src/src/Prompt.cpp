#include "Main.h"

Prompt::Prompt(const char* text, Hash control)
	: Prompt(text, control, Standard)
{
}

Prompt::Prompt(const char* text, Hash control, PromptMode mode)
{
	handle = HUD::_UIPROMPT_REGISTER_BEGIN();
	setControl(control);
	setText(text);
	setTargetEntity(NULL);
	setMode(mode);
	HUD::_UIPROMPT_SET_ATTRIBUTE(handle, 18, 1);
	HUD::_UIPROMPT_REGISTER_END(this->handle);

	semiHoldShouldReturn = false;
	isEnabled = true;
	isVisible = false;
}

Entity Prompt::getTargetEntity()
{
	return this->targetEntity;
}

bool Prompt::getIsEnabled()
{
	return isEnabled;
}

void Prompt::setText(const char* text)
{
	this->text = text;
	const char* textLabel = MISC::VAR_STRING(10, "LITERAL_STRING", text);
	HUD::_UIPROMPT_SET_TEXT(this->handle, textLabel);
}

void Prompt::setControl(Hash control)
{
	this->control = control;
	HUD::_UIPROMPT_SET_CONTROL_ACTION(this->handle, control);
}

Hash Prompt::getControl()
{
	return control;
}

void Prompt::setTargetEntity(Entity target)
{
	this->targetEntity = target;

	if (!target)
	{
		HUD::_UIPROMPT_SET_GROUP(this->handle, 0, 0);
		return;
	}

	int targetEntityGroupId = HUD::_UIPROMPT_GET_GROUP_ID_FOR_TARGET_ENTITY(target);
	if (targetEntityGroupId)
	{
		HUD::_UIPROMPT_SET_GROUP(this->handle, targetEntityGroupId, 0);
	}
}

void Prompt::setGroup(int group)
{
	HUD::_UIPROMPT_SET_GROUP(this->handle, group, 0);
}

void Prompt::attachToCampfire()
{
	setGroup(1754796591); // Camp fire group
}

void Prompt::attachToRestingScenario()
{
	setGroup(342152817); // Resting scenario group
}

void Prompt::setPriority(int priority) 
{
	HUD::_UIPROMPT_SET_PRIORITY(handle, priority);
}

void Prompt::setMode(PromptMode mode)
{
	this->mode = mode;

	switch (mode)
	{
	case Standard:
		HUD::_UIPROMPT_SET_STANDARD_MODE(handle, 1);
		break;

	case Hold:
		HUD::_UIPROMPT_SET_HOLD_MODE(handle, 1);
		break;
	case SemiHold:
		HUD::_UIPROMPT_SET_HOLD_MODE(handle, 1);
		break;
	case Mash:
		HUD::_UIPROMPT_SET_MASH_MANUAL_MODE(handle, 1, 0, 0, 0);
		break;
	}
}

bool Prompt::isActivatedByPlayer()
{
	if (!this->isEnabled || !this->isVisible)
	{
		return false;
	}

	switch (mode)
	{
	case Standard:
		return HUD::_UIPROMPT_HAS_STANDARD_MODE_COMPLETED(handle, 0);
	case Hold:
		return HUD::_UIPROMPT_HAS_HOLD_MODE_COMPLETED(handle);
	case SemiHold:
		if (HUD::_UIPROMPT_HAS_HOLD_MODE_COMPLETED(handle))
		{
			if (semiHoldShouldReturn == true)
			{
				return false;
			}

			semiHoldShouldReturn = true;
			return true;
		}
		else
		{
			semiHoldShouldReturn = false;
		}
	case Mash:
		return HUD::_UIPROMPT_HAS_MASH_MODE_COMPLETED(handle);
	}
}

bool Prompt::isControlPressed() {
	return PAD::IS_DISABLED_CONTROL_PRESSED(0, control);
}

void Prompt::setIsEnabled(bool isEnabled)
{
	this->isEnabled = isEnabled;
	update();
}

void Prompt::show()
{
	isVisible = true;
	update();
}

void Prompt::hide()
{
	isVisible = false;
	update();
}

void Prompt::remove()
{
	HUD::_UIPROMPT_DELETE(handle);
}

void Prompt::update()
{
	if (isVisible)
	{
		HUD::_UIPROMPT_SET_ENABLED(this->handle, isEnabled);
		HUD::_UIPROMPT_SET_VISIBLE(this->handle, true);
	}
	else
	{
		HUD::_UIPROMPT_SET_ENABLED(this->handle, false);
		HUD::_UIPROMPT_SET_VISIBLE(this->handle, false);
	}
}

float Prompt::getMashModeProgress()
{
	return HUD::_UIPROMPT_GET_MASH_MODE_PROGRESS(handle);
}

void Prompt::setMashModeIncreasePerPress(float rate)
{
	HUD::_UIPROMPT_SET_MASH_MANUAL_MODE_INCREASE_PER_PRESS(handle, rate);
}

void Prompt::setMashModeGrowthSpeed(float speed)
{
	HUD::_UIPROMPT_SET_MASH_MANUAL_MODE_PRESSED_GROWTH_SPEED(handle, speed);
}

void Prompt::setMashModeDecaySpeed(float speed)
{
	HUD::_UIPROMPT_SET_MASH_MANUAL_MODE_DECAY_SPEED(handle, speed);
}

void Prompt::setUrgentPulsating(bool toggle)
{
	HUD::_UIPROMPT_SET_URGENT_PULSING_ENABLED(handle, toggle);
}

bool Prompt::isUrgentPulsating()
{
	return HUD::_UIPROMPT_GET_URGENT_PULSING_ENABLED(handle);
}