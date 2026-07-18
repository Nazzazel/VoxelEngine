#pragma once

#include "lve_pipeline.hpp"
#include "lve_window.hpp"

#include "lve_device.hpp"
#include "lve_swap_chain.hpp"

namespace lve {
class FirstApp {
 public:
  static constexpr int WIDTH = 800;
  static constexpr int HEIGHT = 600;

  void run();

 private:
  LveWindow lveWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
  LveDevice lveDevice{ lveWindow };
  LveSwapChain swapChain{lveDevice, lveWindow.getExtent() };
  LvePipeline pipeline{
	  lveDevice,
	  "shaders/simple_shader.vert.spv", 
	  "shaders/simple_shader.frag.spv",
	  LvePipeline::defultPipelineConfigInfo(WIDTH,HEIGHT)
  };
};
}  // namespace lve
//a)shape
//b) size
//c) rectangle
//d) horizontal
//e) vertical
//f) square
//g) diagonal
//h) lower
//i) corner
//j) triangle
//k) angle
//l) right angle
//m) parallel
//n) upper
//o) lower
//p) centre
