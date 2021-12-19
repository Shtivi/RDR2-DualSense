#pragma once

enum PromptMode
{
	Standard,
	Hold,
	SemiHold,
	Mash
};

class Prompt
{
	public:
		int handle;

	private: 
		bool isEnabled;
		bool isVisible;
		const char* text;
		Hash control;
		Entity targetEntity;
		PromptMode mode;
		bool semiHoldShouldReturn;

	public: 
		Prompt(const char* text, Hash control);
		Prompt(const char* text, Hash control, PromptMode mode);

		Entity getTargetEntity();
		bool getIsEnabled();

		void setText(const char* text);
		void setControl(Hash control);
		Hash getControl();
		void setTargetEntity(Entity entity);
		void setPriority(int priority);
		void setMode(PromptMode mode);
		float getMashModeProgress();
		void setMashModeIncreasePerPress(float rate);
		void setMashModeGrowthSpeed(float speed);
		void setMashModeDecaySpeed(float speed);
		void setUrgentPulsating(bool toggle);
		bool isUrgentPulsating();
		void setIsEnabled(bool enabled);
		bool isControlPressed();
		void setGroup(int group);
		void attachToCampfire();
		void attachToRestingScenario();

		bool isActivatedByPlayer();
		void show();
		void hide();
		void remove();

	private:
		void update();
};