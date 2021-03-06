#include <tests/test.hpp>


namespace Test {


App::App(Core::Context &ctx)
: m_world(ctx)
, m_ctx(ctx)
{
}


App::~App()
{
}


void
App::on_think()
{
  m_world.think();
}


Core::World&
App::get_world()
{
  return m_world;
}


Core::Context&
App::get_ctx()
{
  return m_ctx;
}


} // ns