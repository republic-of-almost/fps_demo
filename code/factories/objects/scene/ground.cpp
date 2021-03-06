/*
  Warning
  --
  This file is auto-generated changes here may be overwritten.
*/
#include "ground.hpp"
#include <core/world/world.hpp>
#include <core/entity/entity.hpp>
#include <core/entity/entity_ref.hpp>
#include <core/entity/entity_components.hpp>
#include <core/transform/transform.hpp>
#include <core/renderer/renderer.hpp>
#include <core/physics/rigidbody.hpp>
#include <core/renderer/renderer.hpp>
#include <core/renderer/material_renderer.hpp>
#include <utilities/logging.hpp>
#include <assert.h>

// Needed to add these
#include <core/physics/collider.hpp>
#include <core/physics/box_collider.hpp>


namespace Factory_entity {


Core::Entity
ground_create(Core::World &world, const Core::Transform *override_transform)
{
  // Create Entity
  Core::Entity entity(world);
  
  // Setup entity
  {
    entity.set_name("Ground");
  
    // Set tags
    constexpr uint32_t tag_static = 8;
    constexpr uint32_t tag_scene = 16;
    entity.set_tags(tag_static | tag_scene);
  }  
  
  // Transform
  {
    if(!override_transform)
    {
      Core::Entity_component::set_transform(
        entity,
        Core::Transform(
          math::vec3_init(0, 0, 0),
          math::vec3_init(75, 1, 75),
          math::quat_init() // todo
        )
      );
    }
    else
    {
      Core::Entity_component::set_transform(
        entity,
        *override_transform
      );
    }
  }
  
  // Setup rigidbody
  {
      const Core::Box_collider box(0.5f, 0.5f, 0.5f);

      Core::Rigidbody rb;
      rb.set_mass(0.f);
      rb.set_is_kinematic(true);
      rb.set_collider(box);
    
      Core::Entity_component::set_rigidbody(entity, rb);
  }
  
  // Setup Renderer
  {
//    Core::Material_renderer mat_renderer;
//    
//    entity.set_renderer(mat_renderer);
  }

  return entity;
} // ground_create function

} // ns
