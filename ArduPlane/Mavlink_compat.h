/*
  compatibility header during transition to MAVLink 1.0
 */

#ifdef MAVLINK10
// in MAVLink 1.0 'waypoint' becomes 'mission'. We can remove these
// mappings once we are not trying to support both protocols

#define MAVLINK_MSG_ID_WAYPOINT_CURRENT MAVLINK_MSG_ID_MISSION_CURRENT
#define MAVLINK_MSG_ID_WAYPOINT_CURRENT_LEN MAVLINK_MSG_ID_MISSION_CURRENT_LEN
#define mavlink_msg_waypoint_current_send mavlink_msg_mission_current_send
#define mavlink_msg_waypoint_current_decode mavlink_msg_mission_current_decode

#define MAVLINK_MSG_ID_WAYPOINT_COUNT MAVLINK_MSG_ID_MISSION_COUNT
#define MAVLINK_MSG_ID_WAYPOINT_COUNT_LEN MAVLINK_MSG_ID_MISSION_COUNT_LEN
#define mavlink_msg_waypoint_count_send mavlink_msg_mission_count_send
#define mavlink_msg_waypoint_count_decode mavlink_msg_mission_count_decode
#define mavlink_waypoint_count_t mavlink_mission_count_t

#define MAVLINK_MSG_ID_WAYPOINT_REQUEST MAVLINK_MSG_ID_MISSION_REQUEST
#define MAVLINK_MSG_ID_WAYPOINT_REQUEST_LEN MAVLINK_MSG_ID_MISSION_REQUEST_LEN
#define mavlink_msg_waypoint_request_send mavlink_msg_mission_request_send
#define mavlink_msg_waypoint_request_decode mavlink_msg_mission_request_decode
#define mavlink_waypoint_request_t mavlink_mission_request_t

#define MAVLINK_MSG_ID_WAYPOINT_REQUEST_LIST MAVLINK_MSG_ID_MISSION_REQUEST_LIST
#define MAVLINK_MSG_ID_WAYPOINT_REQUEST_LIST_LEN MAVLINK_MSG_ID_MISSION_REQUEST_LIST_LEN
#define mavlink_msg_waypoint_request_list_send mavlink_msg_mission_request_list_send
#define mavlink_msg_waypoint_request_list_decode mavlink_msg_mission_request_list_decode
#define mavlink_waypoint_request_list_t mavlink_mission_request_list_t

#define MAVLINK_MSG_ID_WAYPOINT MAVLINK_MSG_ID_MISSION_ITEM
#define MAVLINK_MSG_ID_WAYPOINT_LEN MAVLINK_MSG_ID_MISSION_ITEM_LEN
#define mavlink_msg_waypoint_send mavlink_msg_mission_item_send
#define mavlink_msg_waypoint_decode mavlink_msg_mission_item_decode
#define mavlink_waypoint_t mavlink_mission_item_t

#define MAVLINK_MSG_ID_WAYPOINT_ACK MAVLINK_MSG_ID_MISSION_ACK
#define MAVLINK_MSG_ID_WAYPOINT_ACK_LEN MAVLINK_MSG_ID_MISSION_ACK_LEN
#define mavlink_msg_waypoint_ack_send mavlink_msg_mission_ack_send
#define mavlink_msg_waypoint_ack_decode mavlink_msg_mission_ack_decode
#define mavlink_waypoint_ack_t mavlink_mission_ack_t

#define MAVLINK_MSG_ID_WAYPOINT_CLEAR_ALL MAVLINK_MSG_ID_MISSION_CLEAR_ALL
#define MAVLINK_MSG_ID_WAYPOINT_CLEAR_ALL_LEN MAVLINK_MSG_ID_MISSION_CLEAR_ALL_LEN
#define mavlink_msg_waypoint_clear_all_send mavlink_msg_mission_clear_all_send
#define mavlink_msg_waypoint_clear_all_decode mavlink_msg_mission_clear_all_decode
#define mavlink_waypoint_clear_all_t mavlink_mission_clear_all_t

#define MAVLINK_MSG_ID_WAYPOINT_SET_CURRENT MAVLINK_MSG_ID_MISSION_SET_CURRENT
#define MAVLINK_MSG_ID_WAYPOINT_SET_CURRENT_LEN MAVLINK_MSG_ID_MISSION_SET_CURRENT_LEN
#define mavlink_msg_waypoint_set_current_send mavlink_msg_mission_set_current_send
#define mavlink_msg_waypoint_set_current_decode mavlink_msg_mission_set_current_decode
#define mavlink_waypoint_set_current_t mavlink_mission_set_current_t

static uint8_t mav_var_type(AP_Meta_class::Type_id t)
{
    if (t == AP_Var::k_typeid_int8) {
        return MAV_VAR_INT8;
    }
    if (t == AP_Var::k_typeid_int16) {
        return MAV_VAR_INT16;
    }
    if (t == AP_Var::k_typeid_int32) {
        return MAV_VAR_INT32;
    }
    // treat any others as float
    return MAV_VAR_FLOAT;
}

#define MAV_FIXED_WING MAV_TYPE_FIXED_WING

#else

#define MAV_MISSION_ACCEPTED 0
#define MAV_MISSION_UNSUPPORTED       1
#define MAV_MISSION_UNSUPPORTED_FRAME 1
#define MAV_MISSION_ERROR             1
#define MAV_MISSION_INVALID_SEQUENCE  1

#endif