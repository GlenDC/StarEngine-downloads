#pragma once

#include <defines.h>
#include <Logger.h>
#include <Context.h>
#include <Scenes/BaseScene.h>

class ExampleScene : public star::BaseScene
{
public:
	ExampleScene(const tstring& name);
	virtual ~ExampleScene();

	virtual void CreateObjects();
	virtual void AfterInitializedObjects();

	virtual void OnActivate();
	virtual void OnDeactivate();

	virtual void Update(const star::Context& context);
	virtual void Draw();

private:

	ExampleScene(const ExampleScene& t);
	ExampleScene(ExampleScene&& t);
	ExampleScene& operator=(const ExampleScene& t);
	ExampleScene& operator=(ExampleScene&& t);
};
