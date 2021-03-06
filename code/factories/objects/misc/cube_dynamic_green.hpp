/*
  Warning
  --
  This file is auto-generated changes here may be overwritten.
*/
#ifndef CUBE_DYNAMIC_GREEN_INCLUDED_AEF29A98_4BA9_4FDE_9C75_CF320EE10CA8
#define CUBE_DYNAMIC_GREEN_INCLUDED_AEF29A98_4BA9_4FDE_9C75_CF320EE10CA8


#include <core/common/core_fwd.hpp>
#include <stdint.h>


/*
  Factory Entity Method
  --
  Creates a Cube_dynamic_green entity.
*/


namespace Factory_entity {


/*!
  Factory Method
  --
  Creates the Cube_dynamic_green entity.
  Takes in an optional tranform, otherwise it will be created with the
  the transform specified in the function. 
*/
Core::Entity
cube_dynamic_green_create(Core::World &world, const Core::Transform *override_transform = nullptr);


// Helper functions


/*!
  Returns the name the Cube_dynamic_green entity is created with.
*/
constexpr const char* cube_dynamic_green_default_name() { return "Cube_dynamic_green"; }


/*!
  Returns the tags the Cube_dynamic_green entity is created with.
*/
constexpr uint32_t cube_dynamic_green_default_tags() { return 4; }


} // ns


#endif // inc guard
