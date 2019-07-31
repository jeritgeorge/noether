/*
 * Copyright (c) 2018, Southwest Research Institute
 * All rights reserved.*
 * tool_path_generator.h
 *
 *  Created on: Nov 15, 2018
 *      Author: Jorge Nicho
 */

#ifndef INCLUDE_TOOL_PATH_PLANNER_RASTER_PATH_GENERATOR_H_
#define INCLUDE_TOOL_PATH_PLANNER_RASTER_PATH_GENERATOR_H_

#include <geometry_msgs/PoseArray.h>
#include <shape_msgs/Mesh.h>
#include <boost/optional.hpp>

#include "tool_path_planner_base.h"

namespace tool_path_planner {

/**
 * @class tool_path_planner::RasterPathGenerator
 * @details Generates a raster tool path from a surface using the RasterToolPathPlanner and then sequences the path
 *        so that the points are properly ordered relative to the cut direction.
 */
using ToolPaths = std::vector<tool_path_planner::ProcessPath>;

class RasterPathGenerator {
public:
	RasterPathGenerator();
	virtual ~RasterPathGenerator();

	boost::optional< std::vector<ToolPaths> > generate(const tool_path_planner::ProcessTool& path_gen_config,
      const std::vector<pcl::PolygonMesh>& meshes);

  /**
   * @brief plans a tool path using a default configuration
   * @param path_gen_config The configuration data
   * @param mesh  The mesh data on which to generate a tool path
   * @return  The tool path
   */
	boost::optional<std::vector<geometry_msgs::PoseArray>> generate(const tool_path_planner::ProcessTool& path_gen_config,
			const pcl::PolygonMesh& mesh) const;

  /**
   * @brief plans a tool path using a default configuration
   * @param path_gen_config The configuration data
   * @param mesh  The mesh data on which to generate a tool path
   * @return  The tool path
   */
	boost::optional<std::vector<geometry_msgs::PoseArray>> generate(const tool_path_planner::ProcessTool& path_gen_config,
			const shape_msgs::Mesh& mesh) const;

	/**
	 * @brief Generates a ProcessTool configuration structure with default parameters filled in.
	 * @return  The ProcessTool structure.
	 */
  static tool_path_planner::ProcessTool generateDefaultToolConfig();

};

} /* namespace tool_path_planner */

#endif /* INCLUDE_TOOL_PATH_PLANNER_RASTER_PATH_GENERATOR_H_ */
