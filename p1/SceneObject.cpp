//[]---------------------------------------------------------------[]
//|                                                                 |
//| Copyright (C) 2018 Orthrus Group.                               |
//|                                                                 |
//| This software is provided 'as-is', without any express or       |
//| implied warranty. In no event will the authors be held liable   |
//| for any damages arising from the use of this software.          |
//|                                                                 |
//| Permission is granted to anyone to use this software for any    |
//| purpose, including commercial applications, and to alter it and |
//| redistribute it freely, subject to the following restrictions:  |
//|                                                                 |
//| 1. The origin of this software must not be misrepresented; you  |
//| must not claim that you wrote the original software. If you use |
//| this software in a product, an acknowledgment in the product    |
//| documentation would be appreciated but is not required.         |
//|                                                                 |
//| 2. Altered source versions must be plainly marked as such, and  |
//| must not be misrepresented as being the original software.      |
//|                                                                 |
//| 3. This notice may not be removed or altered from any source    |
//| distribution.                                                   |
//|                                                                 |
//[]---------------------------------------------------------------[]
//
// OVERVIEW: SceneObject.cpp
// ========
// Source file for scene object.
//
// Author(s): Paulo Pagliosa (and your name)
// Last revision: 25/08/2018

#include "SceneObject.h"
#include "Scene.h"

namespace cg
{ // begin namespace cg


/////////////////////////////////////////////////////////////////////
//
// SceneObject implementation
// ===========



auto
SceneObject::addSceneObjectChild(SceneObject* child)
{
	sceneObjectList.push_back(child);
}

auto 
SceneObject::removeSceneObjectChild(SceneObject* child)
{
	sceneObjectList.remove(child);
}

void
SceneObject::setParent(SceneObject* parent)
{
	//Se o pai atual � diferente do novo pai:

	if (this->parent() != nullptr) {
		this->_parent->removeSceneObjectChild(this);
	
	}
	if (parent != nullptr) {
		parent->addSceneObjectChild(this);
		this->_parent = parent;
	}else {
		scene()->addObjectScene(*this);
	}
	
}
auto
SceneObject::addComponent(Component* component)
{
	this->componentList.push_back(component);
}

auto 
SceneObject::removeComponent(Component* component)
{
	componentList.remove(component);
}


} // end namespace cg
