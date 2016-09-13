#include <core/context/context.hpp>
#include <tests/material_test.hpp>


// - phys test
#include <3rdparty/qu3e/q3.h>


int
main()
{
  // ** SETUP CONTEXT ** //
  Core::Context_setup setup;
  setup.vsync = true;
  Core::Context context(800, 480, false, "Tests", setup);
  
  
  // ** CREATE TEST ** //
  std::unique_ptr<Test::App> curr_test(new Test::Material_test(context));


  // ** RUN TEST ** //
  while(context)
  {
    curr_test->on_think();
  }
  
  
  return 0;
}