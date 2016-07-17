#include <core/world/world.hpp>
#include <core/context/context.hpp>
#include <core/entity/entity.hpp>
#include <core/entity/entity_ref.hpp>
#include <core/camera/camera.hpp>
#include <core/resources/shader.hpp>
#include <core/resources/texture.hpp>
#include <core/resources/material.hpp>
#include <core/model/model.hpp>
#include <core/common/directory.hpp>
#include <core/transform/transform.hpp>
#include <core/renderer/material_renderer.hpp>
#include <core/renderer/renderer.hpp>
#include <core/input/controller.hpp>
#include <core/color/color_predefined.hpp>

/*
  FPS Demo
  --
  Creates a simple fps style scene.
*/

int
main()
{
  // ** SETUP WORLD AND CONTEXT ** //

  Core::Context_setup setup;
  setup.vsync = true;
  Core::Context context(800, 480, false, "FPS Test", setup);
  Core::World world(context);
  
  // ** SETUP RESOURCES ** //
  
  const Core::Shader shader_fullbright(Core::Directory::resource_path("assets/shaders/basic_fullbright.ogl"));
  const Core::Texture texture_orange(Core::Directory::resource_path("assets/textures/dev_grid_orange_512.png"));
  Core::Material material_fb_or("fullbright-orange");
  material_fb_or.set_shader(shader_fullbright);
  material_fb_or.set_map_01(texture_orange);
  
  Core::Model model_plane(Core::Directory::resource_path("assets/models/unit_plane.obj"));
  
  // ** SETUP ENTITIES ** //

  Core::Entity cam_entity(world);
  Core::Camera main_camera(world);
  {
    cam_entity.set_name("Camera");
    
    Core::Transform transform;
    transform.set_position(math::vec3_init(0.f, 1.f, 0.f));
    
    cam_entity.set_transform(transform);
    
    main_camera.set_attached_entity(cam_entity);
    main_camera.set_priority(1);
    
    main_camera.set_width(context.get_width());
    main_camera.set_height(context.get_height());
    main_camera.set_feild_of_view(math::quart_tau() * 0.5f);
    main_camera.set_clear_color(Core::Color_utils::gray());
  }
  
  Core::Entity ground_entity(world);
  {
    ground_entity.set_name("Ground Entity");
    
    Core::Transform transform;
    transform.set_scale(math::vec3_init(10.f, 1.f, 10.f));
    
    ground_entity.set_transform(transform);
    
    Core::Material_renderer ground_renderer;
    ground_renderer.set_material(material_fb_or);
    ground_renderer.set_model(model_plane);
    
    ground_entity.set_renderer(ground_renderer);
  }
  
  // ** RUN WINDOW AND APP ** //
  
  while(context.is_open())
  {
    // ** FPS INPUT ** //
    {
      Core::Input::Controller controller(context, 0);
      Core::Transform transform = cam_entity.get_transform();
      
      // Move Axis
      {
        const float move_mul = world.get_delta_time() * 4.f;
      
        const math::vec3 fwd      = math::vec3_scale(transform.get_forward(), controller.get_axis(0).y * move_mul);
        const math::vec3 left     = math::vec3_scale(transform.get_left(), controller.get_axis(0).x * move_mul);
        const math::vec3 curr_pos = transform.get_position();
        const math::vec3 new_pos  = math::vec3_add(math::vec3_add(curr_pos, fwd), left);
        
        transform.set_position(new_pos);
      }
      
      // Rot Axis
      {
        const float rot_mul = world.get_delta_time() * 3.f;
      
        static float accum_x = 0.f;
        static float accum_y = 0.f;
        
        accum_x += controller.get_axis(1).x * rot_mul;
        accum_y += controller.get_axis(1).y * rot_mul;
        
        const math::quat yaw   = math::quat_init_with_axis_angle(Core::Transform::get_world_up(), accum_x);
        const math::quat pitch = math::quat_init_with_axis_angle(Core::Transform::get_world_left(), accum_y);
        const math::quat rot   = math::quat_multiply(pitch, yaw);
                
        transform.set_rotation(rot);
      }
      
      cam_entity.set_transform(transform);
    }
  
    // ** UPDATE THE WORLD ** //
    
    world.think();
  }
  
  
  return 0;
}