#ifndef LOCAL_PLANNER_ASTAR_G_STATIC_H
#define LOCAL_PLANNER_ASTAR_G_STATIC_H

/// PROJECT
#include <path_follower/local_planner/local_planner_astar.h>
#include <path_follower/local_planner/local_planner_star_g.h>
#include <path_follower/local_planner/local_planner_star_static.h>

class LocalPlannerAStarGStatic : public LocalPlannerAStar, public LocalPlannerStarG, public LocalPlannerStarStatic
{
public:
    LocalPlannerAStarGStatic(PathFollower& controller, tf::Transformer &transformer,
                       const ros::Duration& update_interval);
};

#endif // LOCAL_PLANNER_ASTAR_G_STATIC_H
