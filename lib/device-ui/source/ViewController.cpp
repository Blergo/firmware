#include "ViewController.h"
#include "ILog.h"
#include "MeshtasticView.h"
#include "assert.h"
#include <algorithm>

const size_t DATA_PAYLOAD_LEN = meshtastic_Constants_DATA_PAYLOAD_LEN;

/**
 * @brief mediate between GUI view and client interface
 *
 */
ViewController::ViewController() : view(nullptr), client(nullptr), sendId(1), myNodeNum(0), requestConfigRequired(true) {}

void ViewController::init(MeshtasticView *gui, IClientBase *_client)
{
    time(&lastrun10);
    lastrun10 += 10;
    view = gui;
    client = _client;
    if (client) {
        client->init();
        client->connect();
    }
}

/**
 * @brief runOnce need to be called periodically to process send/receive queues
 *
 */
void ViewController::runOnce(void)
{
    if (client) {
        requestConfig();
        receive();

        // executed every 10s:
        time_t curtime;
        time(&curtime);

        if (curtime - lastrun10 >= 10) {
            lastrun10 = curtime;
            if (!client->isConnected())
                client->connect();
        }
    }
}

bool ViewController::sleep(int16_t pin)
{
    if (client)
        return client->sleep(pin);
    else
        return false;
}

void ViewController::processEvent(void) {}

uint32_t ViewController::requestDeviceConfig(uint32_t nodeId)
{
    return requestConfig(meshtastic_AdminMessage_ConfigType_DEVICE_CONFIG, nodeId ? nodeId : myNodeNum);
}

uint32_t ViewController::requestPositionConfig(uint32_t nodeId)
{
    return requestConfig(meshtastic_AdminMessage_ConfigType_POSITION_CONFIG, nodeId ? nodeId : myNodeNum);
}

uint32_t ViewController::requestPowerConfig(uint32_t nodeId)
{
    return requestConfig(meshtastic_AdminMessage_ConfigType_POWER_CONFIG, nodeId ? nodeId : myNodeNum);
}

uint32_t ViewController::requestNetworkConfig(uint32_t nodeId)
{
    return requestConfig(meshtastic_AdminMessage_ConfigType_NETWORK_CONFIG, nodeId ? nodeId : myNodeNum);
}

uint32_t ViewController::requestDisplayConfig(uint32_t nodeId)
{
    return requestConfig(meshtastic_AdminMessage_ConfigType_DISPLAY_CONFIG, nodeId ? nodeId : myNodeNum);
}

uint32_t ViewController::requestLoRaConfig(uint32_t nodeId)
{
    return requestConfig(meshtastic_AdminMessage_ConfigType_LORA_CONFIG, nodeId ? nodeId : myNodeNum);
}

uint32_t ViewController::requestBluetoothConfig(uint32_t nodeId)
{
    return requestConfig(meshtastic_AdminMessage_ConfigType_BLUETOOTH_CONFIG, nodeId ? nodeId : myNodeNum);
}

uint32_t ViewController::requestRingtone(uint32_t nodeId)
{
    return sendAdminMessage(meshtastic_AdminMessage{.which_payload_variant = meshtastic_AdminMessage_get_ringtone_request_tag,
                                                    .get_ringtone_request = true},
                            nodeId ? nodeId : myNodeNum);
}

/**
 * Request specific device config block
 */
uint32_t ViewController::requestConfig(meshtastic_AdminMessage_ConfigType type, uint32_t nodeId)
{
    return sendAdminMessage(meshtastic_AdminMessage{.which_payload_variant = meshtastic_AdminMessage_get_config_request_tag,
                                                    .get_config_request = type},
                            nodeId ? nodeId : myNodeNum);
}

bool ViewController::requestReboot(int32_t seconds, uint32_t nodeId)
{
    return sendAdminMessage(
        meshtastic_AdminMessage{.which_payload_variant = meshtastic_AdminMessage_reboot_seconds_tag, .reboot_seconds = seconds},
        nodeId ? nodeId : myNodeNum);
}

bool ViewController::requestRebootOTA(int32_t seconds, uint32_t nodeId)
{
    return sendAdminMessage(meshtastic_AdminMessage{.which_payload_variant = meshtastic_AdminMessage_reboot_ota_seconds_tag,
                                                    .reboot_ota_seconds = seconds},
                            nodeId ? nodeId : myNodeNum);
}

bool ViewController::requestShutdown(int32_t seconds, uint32_t nodeId)
{
    return sendAdminMessage(meshtastic_AdminMessage{.which_payload_variant = meshtastic_AdminMessage_shutdown_seconds_tag,
                                                    .shutdown_seconds = seconds},
                            nodeId ? nodeId : myNodeNum);
}

/**
 * @brief request factory reset or nodedb reset
 *
 * @param factoryReset set to false if only nodeDB reset is desired
 * @param nodeId
 * @return true
 * @return false
 */
bool ViewController::requestReset(bool factoryReset, uint32_t nodeId)
{
    return sendAdminMessage(factoryReset
                                ? meshtastic_AdminMessage{.which_payload_variant = meshtastic_AdminMessage_factory_reset_tag}
                                : meshtastic_AdminMessage{.which_payload_variant = meshtastic_AdminMessage_nodedb_reset_tag},
                            nodeId ? nodeId : myNodeNum);
}

bool ViewController::sendConfig(const meshtastic_User &user, uint32_t nodeId)
{
    return sendAdminMessage(
        meshtastic_AdminMessage{.which_payload_variant = meshtastic_AdminMessage_set_owner_tag, .set_owner{user}},
        nodeId ? nodeId : myNodeNum);
}

bool ViewController::sendConfig(meshtastic_Config_DeviceConfig &&device, uint32_t nodeId)
{
    return sendAdminMessage(meshtastic_AdminMessage{.which_payload_variant = meshtastic_AdminMessage_set_config_tag,
                                                    .set_config{.which_payload_variant = meshtastic_Config_device_tag,
                                                                .payload_variant{.device = device}}},
                            nodeId ? nodeId : myNodeNum);
}

bool ViewController::sendConfig(meshtastic_Config_PositionConfig &&position, uint32_t nodeId)
{
    return sendAdminMessage(meshtastic_AdminMessage{.which_payload_variant = meshtastic_AdminMessage_set_config_tag,
                                                    .set_config{.which_payload_variant = meshtastic_Config_position_tag,
                                                                .payload_variant{.position = position}}},
                            nodeId ? nodeId : myNodeNum);
}

bool ViewController::sendConfig(meshtastic_Config_PowerConfig &&power, uint32_t nodeId)
{
    return sendAdminMessage(meshtastic_AdminMessage{.which_payload_variant = meshtastic_AdminMessage_set_config_tag,
                                                    .set_config{.which_payload_variant = meshtastic_Config_power_tag,
                                                                .payload_variant{.power = power}}},
                            nodeId ? nodeId : myNodeNum);
}

bool ViewController::sendConfig(meshtastic_Config_NetworkConfig &&network, uint32_t nodeId)
{
    return sendAdminMessage(meshtastic_AdminMessage{.which_payload_variant = meshtastic_AdminMessage_set_config_tag,
                                                    .set_config{.which_payload_variant = meshtastic_Config_network_tag,
                                                                .payload_variant{.network = network}}},
                            nodeId ? nodeId : myNodeNum);
}

bool ViewController::sendConfig(meshtastic_Config_DisplayConfig &&display, uint32_t nodeId)
{
    return sendAdminMessage(meshtastic_AdminMessage{.which_payload_variant = meshtastic_AdminMessage_set_config_tag,
                                                    .set_config{.which_payload_variant = meshtastic_Config_display_tag,
                                                                .payload_variant{.display = display}}},
                            nodeId ? nodeId : myNodeNum);
}

bool ViewController::sendConfig(meshtastic_Config_LoRaConfig &&lora, uint32_t nodeId)
{
    return sendAdminMessage(
        meshtastic_AdminMessage{.which_payload_variant = meshtastic_AdminMessage_set_config_tag,
                                .set_config{.which_payload_variant = meshtastic_Config_lora_tag, .payload_variant{.lora = lora}}},
        nodeId ? nodeId : myNodeNum);
}

bool ViewController::sendConfig(meshtastic_Config_BluetoothConfig &&bluetooth, uint32_t nodeId)
{
    return sendAdminMessage(meshtastic_AdminMessage{.which_payload_variant = meshtastic_AdminMessage_set_config_tag,
                                                    .set_config{.which_payload_variant = meshtastic_Config_bluetooth_tag,
                                                                .payload_variant{.bluetooth = bluetooth}}},
                            nodeId ? nodeId : myNodeNum);
}

bool ViewController::sendConfig(meshtastic_Channel &channel, uint32_t nodeId)
{
    return sendAdminMessage(
        meshtastic_AdminMessage{.which_payload_variant = meshtastic_AdminMessage_set_channel_tag, .set_channel{channel}},
        nodeId ? nodeId : myNodeNum);
}

// module config

bool ViewController::sendConfig(meshtastic_ModuleConfig_MQTTConfig &&mqtt, uint32_t nodeId)
{
    return sendAdminMessage(meshtastic_AdminMessage{.which_payload_variant = meshtastic_AdminMessage_set_module_config_tag,
                                                    .set_module_config{.which_payload_variant = meshtastic_ModuleConfig_mqtt_tag,
                                                                       .payload_variant{.mqtt = mqtt}}},
                            nodeId ? nodeId : myNodeNum);
}

bool ViewController::sendConfig(meshtastic_ModuleConfig_SerialConfig &&serial, uint32_t nodeId)
{
    return sendAdminMessage(
        meshtastic_AdminMessage{
            .which_payload_variant = meshtastic_AdminMessage_set_module_config_tag,
            .set_module_config{.which_payload_variant = meshtastic_ModuleConfig_serial_tag, .payload_variant{.serial = serial}}},
        nodeId ? nodeId : myNodeNum);
}

bool ViewController::sendConfig(meshtastic_ModuleConfig_ExternalNotificationConfig &&extNotif, uint32_t nodeId)
{
    return sendAdminMessage(
        meshtastic_AdminMessage{.which_payload_variant = meshtastic_AdminMessage_set_module_config_tag,
                                .set_module_config{.which_payload_variant = meshtastic_ModuleConfig_external_notification_tag,
                                                   .payload_variant{.external_notification = extNotif}}},
        nodeId ? nodeId : myNodeNum);
}

bool ViewController::sendConfig(const char ringtone[230], uint32_t nodeId)
{
    meshtastic_AdminMessage adminMsg{.which_payload_variant = meshtastic_AdminMessage_set_ringtone_message_tag};
    memcpy(adminMsg.set_ringtone_message, ringtone, std::min(strlen(ringtone), (size_t)230U));

    return sendAdminMessage(adminMsg, nodeId ? nodeId : myNodeNum);
}

bool ViewController::sendConfig(meshtastic_ModuleConfig_StoreForwardConfig &&storeForward, uint32_t nodeId)
{
    return sendAdminMessage(
        meshtastic_AdminMessage{.which_payload_variant = meshtastic_AdminMessage_set_module_config_tag,
                                .set_module_config{.which_payload_variant = meshtastic_ModuleConfig_store_forward_tag,
                                                   .payload_variant{.store_forward = storeForward}}},
        nodeId ? nodeId : myNodeNum);
}

bool ViewController::sendConfig(meshtastic_ModuleConfig_RangeTestConfig &&rangeTest, uint32_t nodeId)
{
    return sendAdminMessage(
        meshtastic_AdminMessage{.which_payload_variant = meshtastic_AdminMessage_set_module_config_tag,
                                .set_module_config{.which_payload_variant = meshtastic_ModuleConfig_range_test_tag,
                                                   .payload_variant{.range_test = rangeTest}}},
        nodeId ? nodeId : myNodeNum);
}

bool ViewController::sendConfig(meshtastic_ModuleConfig_TelemetryConfig &&telemetry, uint32_t nodeId)
{
    return sendAdminMessage(
        meshtastic_AdminMessage{.which_payload_variant = meshtastic_AdminMessage_set_module_config_tag,
                                .set_module_config{.which_payload_variant = meshtastic_ModuleConfig_telemetry_tag,
                                                   .payload_variant{.telemetry = telemetry}}},
        nodeId ? nodeId : myNodeNum);
}

bool ViewController::sendConfig(meshtastic_ModuleConfig_CannedMessageConfig &&cannedMessage, uint32_t nodeId)
{
    return sendAdminMessage(
        meshtastic_AdminMessage{.which_payload_variant = meshtastic_AdminMessage_set_module_config_tag,
                                .set_module_config{.which_payload_variant = meshtastic_ModuleConfig_canned_message_tag,
                                                   .payload_variant{.canned_message = cannedMessage}}},
        nodeId ? nodeId : myNodeNum);
}

bool ViewController::sendConfig(meshtastic_ModuleConfig_AudioConfig &&audio, uint32_t nodeId)
{
    return sendAdminMessage(meshtastic_AdminMessage{.which_payload_variant = meshtastic_AdminMessage_set_module_config_tag,
                                                    .set_module_config{.which_payload_variant = meshtastic_ModuleConfig_audio_tag,
                                                                       .payload_variant{.audio = audio}}},
                            nodeId ? nodeId : myNodeNum);
}

bool ViewController::sendConfig(meshtastic_ModuleConfig_RemoteHardwareConfig &&remoteHW, uint32_t nodeId)
{
    return sendAdminMessage(
        meshtastic_AdminMessage{.which_payload_variant = meshtastic_AdminMessage_set_module_config_tag,
                                .set_module_config{.which_payload_variant = meshtastic_ModuleConfig_remote_hardware_tag,
                                                   .payload_variant{.remote_hardware = remoteHW}}},
        nodeId ? nodeId : myNodeNum);
}

bool ViewController::sendConfig(meshtastic_ModuleConfig_NeighborInfoConfig &&neighborInfo, uint32_t nodeId)
{
    return sendAdminMessage(
        meshtastic_AdminMessage{.which_payload_variant = meshtastic_AdminMessage_set_module_config_tag,
                                .set_module_config{.which_payload_variant = meshtastic_ModuleConfig_neighbor_info_tag,
                                                   .payload_variant{.neighbor_info = neighborInfo}}},
        nodeId ? nodeId : myNodeNum);
}

bool ViewController::sendConfig(meshtastic_ModuleConfig_AmbientLightingConfig &&ambientLighting, uint32_t nodeId)
{
    return sendAdminMessage(
        meshtastic_AdminMessage{.which_payload_variant = meshtastic_AdminMessage_set_module_config_tag,
                                .set_module_config{.which_payload_variant = meshtastic_ModuleConfig_ambient_lighting_tag,
                                                   .payload_variant{.ambient_lighting = ambientLighting}}},
        nodeId ? nodeId : myNodeNum);
}

bool ViewController::sendConfig(meshtastic_ModuleConfig_DetectionSensorConfig &&detectionSensor, uint32_t nodeId)
{
    return sendAdminMessage(
        meshtastic_AdminMessage{.which_payload_variant = meshtastic_AdminMessage_set_module_config_tag,
                                .set_module_config{.which_payload_variant = meshtastic_ModuleConfig_detection_sensor_tag,
                                                   .payload_variant{.detection_sensor = detectionSensor}}},
        nodeId ? nodeId : myNodeNum);
}

bool ViewController::sendConfig(meshtastic_ModuleConfig_PaxcounterConfig &&paxCounter, uint32_t nodeId)
{
    return sendAdminMessage(
        meshtastic_AdminMessage{.which_payload_variant = meshtastic_AdminMessage_set_module_config_tag,
                                .set_module_config{.which_payload_variant = meshtastic_ModuleConfig_paxcounter_tag,
                                                   .payload_variant{.paxcounter = paxCounter}}},
        nodeId ? nodeId : myNodeNum);
}

/**
 * @brief Generic admin message (takes lvalue) and variable portnum
 *
 */
bool ViewController::sendAdminMessage(meshtastic_AdminMessage &config, uint32_t nodeId)
{
    meshtastic_Data_payload_t payload;
    payload.size = pb_encode_to_bytes(payload.bytes, DATA_PAYLOAD_LEN, &meshtastic_AdminMessage_msg, &config);
    return send(nodeId, meshtastic_PortNum_ADMIN_APP, payload);
}

/**
 * @brief Generic admin message (takes rvalue)
 *
 */
bool ViewController::sendAdminMessage(meshtastic_AdminMessage &&config, uint32_t nodeId)
{
    meshtastic_Data_payload_t payload;
    payload.size = pb_encode_to_bytes(payload.bytes, DATA_PAYLOAD_LEN, &meshtastic_AdminMessage_msg, &config);
    return send(nodeId, meshtastic_PortNum_ADMIN_APP, payload);
}

void ViewController::sendHeartbeat(void)
{
    if (client->isConnected()) {
        client->send(meshtastic_ToRadio{.which_payload_variant = meshtastic_ToRadio_heartbeat_tag});
    }
}

void ViewController::setConfigRequested(bool required)
{
    requestConfigRequired = required;
}

void ViewController::sendTextMessage(uint32_t to, uint8_t ch, uint32_t requestId, const char *textmsg)
{
    assert(strlen(textmsg) <= (size_t)DATA_PAYLOAD_LEN);
    send(to, ch, requestId, meshtastic_PortNum_TEXT_MESSAGE_APP, (const uint8_t *)textmsg, strlen(textmsg));
}

/**
 * @brief generic send message to configure or request config data
 *
 * @param to destination
 * @param portnum app
 * @param payload
 * @return true
 * @return false
 */
bool ViewController::send(uint32_t to, meshtastic_PortNum portnum, const meshtastic_Data_payload_t &payload)
{
    ILOG_DEBUG("sending meshpacket to radio portnum=%u\n", portnum);
    return client->send(meshtastic_ToRadio{.which_payload_variant = meshtastic_ToRadio_packet_tag,
                                           .packet{.to = to,
                                                   .which_payload_variant = meshtastic_MeshPacket_decoded_tag,
                                                   .decoded{.portnum = portnum, .payload{payload}, .want_response = true},
                                                   .want_ack = (to != 0)}});
}

/**
 * generic send method for sending meshpackets with encoded payload
 */
bool ViewController::send(uint32_t to, uint8_t ch, uint32_t requestId, meshtastic_PortNum portnum, const unsigned char bytes[237],
                          size_t len)
{
    ILOG_DEBUG("sending meshpacket to radio to=0x%08x(%u), ch=%u, portnum=%u, len=%u\n", to, to, (unsigned int)ch, portnum, len);
    // send requires movable lvalue, i.e. a temporary object
    return client->send(meshtastic_ToRadio{
        .which_payload_variant = meshtastic_ToRadio_packet_tag,
        .packet{
            .to = to,
            .channel = ch,
            .which_payload_variant = meshtastic_MeshPacket_decoded_tag,
            .decoded{
                .portnum = portnum,
                .payload{.size = (unsigned short)len,
                         .bytes = {bytes[0],   bytes[1],   bytes[2],   bytes[3],   bytes[4],   bytes[5],   bytes[6],   bytes[7],
                                   bytes[8],   bytes[9],   bytes[10],  bytes[11],  bytes[12],  bytes[13],  bytes[14],  bytes[15],
                                   bytes[16],  bytes[17],  bytes[18],  bytes[19],  bytes[20],  bytes[21],  bytes[22],  bytes[23],
                                   bytes[24],  bytes[25],  bytes[26],  bytes[27],  bytes[28],  bytes[29],  bytes[30],  bytes[31],
                                   bytes[32],  bytes[33],  bytes[34],  bytes[35],  bytes[36],  bytes[37],  bytes[38],  bytes[39],
                                   bytes[40],  bytes[41],  bytes[42],  bytes[43],  bytes[44],  bytes[45],  bytes[46],  bytes[47],
                                   bytes[48],  bytes[49],  bytes[50],  bytes[51],  bytes[52],  bytes[53],  bytes[54],  bytes[55],
                                   bytes[56],  bytes[57],  bytes[58],  bytes[59],  bytes[60],  bytes[61],  bytes[62],  bytes[63],
                                   bytes[64],  bytes[65],  bytes[66],  bytes[67],  bytes[68],  bytes[69],  bytes[70],  bytes[71],
                                   bytes[72],  bytes[73],  bytes[74],  bytes[75],  bytes[76],  bytes[77],  bytes[78],  bytes[79],
                                   bytes[80],  bytes[81],  bytes[82],  bytes[83],  bytes[84],  bytes[85],  bytes[86],  bytes[87],
                                   bytes[88],  bytes[89],  bytes[90],  bytes[91],  bytes[92],  bytes[93],  bytes[94],  bytes[95],
                                   bytes[96],  bytes[97],  bytes[98],  bytes[99],  bytes[100], bytes[101], bytes[102], bytes[103],
                                   bytes[104], bytes[105], bytes[106], bytes[107], bytes[108], bytes[109], bytes[110], bytes[111],
                                   bytes[112], bytes[113], bytes[114], bytes[115], bytes[116], bytes[117], bytes[118], bytes[119],
                                   bytes[120], bytes[121], bytes[122], bytes[123], bytes[124], bytes[125], bytes[126], bytes[127],
                                   bytes[128], bytes[129], bytes[130], bytes[131], bytes[132], bytes[133], bytes[134], bytes[135],
                                   bytes[136], bytes[137], bytes[138], bytes[139], bytes[140], bytes[141], bytes[142], bytes[143],
                                   bytes[144], bytes[145], bytes[146], bytes[147], bytes[148], bytes[149], bytes[150], bytes[151],
                                   bytes[152], bytes[153], bytes[154], bytes[155], bytes[156], bytes[157], bytes[158], bytes[159],
                                   bytes[160], bytes[161], bytes[162], bytes[163], bytes[164], bytes[165], bytes[166], bytes[167],
                                   bytes[168], bytes[169], bytes[170], bytes[171], bytes[172], bytes[173], bytes[174], bytes[175],
                                   bytes[176], bytes[177], bytes[178], bytes[179], bytes[180], bytes[181], bytes[182], bytes[183],
                                   bytes[184], bytes[185], bytes[186], bytes[187], bytes[188], bytes[189], bytes[190], bytes[191],
                                   bytes[192], bytes[193], bytes[194], bytes[195], bytes[196], bytes[197], bytes[198], bytes[199],
                                   bytes[200], bytes[201], bytes[202], bytes[203], bytes[204], bytes[205], bytes[206], bytes[207],
                                   bytes[208], bytes[209], bytes[210], bytes[211], bytes[212], bytes[213], bytes[214], bytes[215],
                                   bytes[216], bytes[217], bytes[218], bytes[219], bytes[220], bytes[221], bytes[222], bytes[223],
                                   bytes[224], bytes[225], bytes[226], bytes[227], bytes[228], bytes[229], bytes[230], bytes[231],
                                   bytes[232], bytes[233], bytes[234], bytes[235], bytes[236]}},
                .want_response = false}, // FIXME: traceRoute, requestPosition, remote config: true
            .id = requestId,
            .hop_limit = 3, // FIXME: use value from setting
            .want_ack = (to != 0)}});
}

bool ViewController::receive(void)
{
    bool gotPacket = false;
    if (client->isConnected()) {
        do {
            meshtastic_FromRadio from = client->receive();
            if (from.which_payload_variant) {
                handleFromRadio(from);
            }
            gotPacket = from.which_payload_variant != 0;
        } while (gotPacket);
        return true;
    }
    return false;
}

/**
 * request full upload of all config data from the radio
 */
void ViewController::requestConfig(void)
{
    if (client->isConnected() && requestConfigRequired) {
        client->send(meshtastic_ToRadio{.which_payload_variant = meshtastic_ToRadio_want_config_id_tag, .want_config_id = 1});
        requestConfigRequired = false;
    }
}

/**
 * @brief request additional config after initial startup finished
 *
 */
void ViewController::requestAdditionalConfig(void)
{
    requestRingtone(myNodeNum);
}

/**
 * request connection status of WLAN/BT/MQTT
 */
bool ViewController::requestDeviceConnectionStatus(void)
{
    return sendAdminMessage(
        meshtastic_AdminMessage{.which_payload_variant = meshtastic_AdminMessage_get_device_connection_status_request_tag,
                                .get_device_connection_status_request = true},
        myNodeNum);
}

bool ViewController::handleFromRadio(const meshtastic_FromRadio &from)
{
    ILOG_DEBUG("handleFromRadio variant %u\n", from.which_payload_variant);
    switch (from.which_payload_variant) {
    case meshtastic_FromRadio_my_info_tag: {
        const meshtastic_MyNodeInfo &info = from.my_info;
        view->setMyInfo(info.my_node_num);
        myNodeNum = info.my_node_num;
        break;
    }
    case meshtastic_FromRadio_packet_tag: {
        const meshtastic_MeshPacket &p = from.packet;
        if (p.which_payload_variant == meshtastic_MeshPacket_decoded_tag) {
            packetReceived(p);
        } else {
            // FIXME: needs implementation when not using PacketClient interface
            ILOG_ERROR("dropping encoded meshpacket id=%u from radio!\n", from.id);
        }
        break;
    }
    case meshtastic_FromRadio_node_info_tag: {
        const meshtastic_NodeInfo &node = from.node_info;
        if (node.has_user) {
            view->addOrUpdateNode(node.num, node.channel, node.user.short_name, node.user.long_name, node.last_heard,
                                  (MeshtasticView::eRole)node.user.role, node.via_mqtt);
        } else {
            view->addOrUpdateNode(node.num, node.channel, node.last_heard, (MeshtasticView::eRole)node.user.role, node.via_mqtt);
        }
        if (node.has_position) {
            view->updatePosition(node.num, node.position.latitude_i, node.position.longitude_i, node.position.altitude, 0,
                                 node.position.precision_bits);
        }
        if (node.has_device_metrics) {
            view->updateMetrics(node.num, node.device_metrics.battery_level, node.device_metrics.voltage,
                                node.device_metrics.channel_utilization, node.device_metrics.air_util_tx);
        }
        break;
    }
    case meshtastic_FromRadio_config_tag: {
        const meshtastic_Config &config = from.config;
        switch (config.which_payload_variant) {
        case meshtastic_Config_device_tag: {
            const meshtastic_Config_DeviceConfig &cfg = config.payload_variant.device;
            view->updateDeviceConfig(cfg);
            break;
        }
        case meshtastic_Config_position_tag: {
            const meshtastic_Config_PositionConfig &cfg = config.payload_variant.position;
            view->updatePositionConfig(cfg);
            break;
        }
        case meshtastic_Config_power_tag: {
            const meshtastic_Config_PowerConfig &cfg = config.payload_variant.power;
            view->updatePowerConfig(cfg);
            break;
        }
        case meshtastic_Config_network_tag: {
            const meshtastic_Config_NetworkConfig &cfg = config.payload_variant.network;
            view->updateNetworkConfig(cfg);
            break;
        }
        case meshtastic_Config_display_tag: {
            const meshtastic_Config_DisplayConfig &cfg = config.payload_variant.display;
            view->updateDisplayConfig(cfg);
            break;
        }
        case meshtastic_Config_lora_tag: {
            const meshtastic_Config_LoRaConfig &cfg = config.payload_variant.lora;
            view->updateLoRaConfig(cfg);
            break;
        }
        case meshtastic_Config_bluetooth_tag: {
            const meshtastic_Config_BluetoothConfig &cfg = config.payload_variant.bluetooth;
            view->updateBluetoothConfig(cfg);
            break;
        }
        default:
            ILOG_ERROR("unsupported device config variant: %u\n", config.which_payload_variant);
            return false;
        }
        break;
    }
    case meshtastic_FromRadio_moduleConfig_tag: {
        const meshtastic_ModuleConfig &module = from.moduleConfig;
        switch (module.which_payload_variant) {
        case meshtastic_ModuleConfig_mqtt_tag: {
            const meshtastic_ModuleConfig_MQTTConfig &cfg = module.payload_variant.mqtt;
            view->updateMQTTModule(cfg);
            break;
        }
        case meshtastic_ModuleConfig_serial_tag: {
            const meshtastic_ModuleConfig_SerialConfig &cfg = module.payload_variant.serial;
            view->updateSerialModule(cfg);
            break;
        }
        case meshtastic_ModuleConfig_external_notification_tag: {
            const meshtastic_ModuleConfig_ExternalNotificationConfig &cfg = module.payload_variant.external_notification;
            view->updateExtNotificationModule(cfg);
            break;
        }
        case meshtastic_ModuleConfig_store_forward_tag: {
            const meshtastic_ModuleConfig_StoreForwardConfig &cfg = module.payload_variant.store_forward;
            view->updateStoreForwardModule(cfg);
            break;
        }
        case meshtastic_ModuleConfig_range_test_tag: {
            const meshtastic_ModuleConfig_RangeTestConfig &cfg = module.payload_variant.range_test;
            view->updateRangeTestModule(cfg);
            break;
        }
        case meshtastic_ModuleConfig_telemetry_tag: {
            const meshtastic_ModuleConfig_TelemetryConfig &cfg = module.payload_variant.telemetry;
            view->updateTelemetryModule(cfg);
            break;
        }
        case meshtastic_ModuleConfig_canned_message_tag: {
            const meshtastic_ModuleConfig_CannedMessageConfig &cfg = module.payload_variant.canned_message;
            view->updateCannedMessageModule(cfg);
            break;
        }
        case meshtastic_ModuleConfig_audio_tag: {
            const meshtastic_ModuleConfig_AudioConfig &cfg = module.payload_variant.audio;
            view->updateAudioModule(cfg);
            break;
        }
        case meshtastic_ModuleConfig_remote_hardware_tag: {
            const meshtastic_ModuleConfig_RemoteHardwareConfig &cfg = module.payload_variant.remote_hardware;
            view->updateRemoteHardwareModule(cfg);
            break;
        }
        case meshtastic_ModuleConfig_neighbor_info_tag: {
            const meshtastic_ModuleConfig_NeighborInfoConfig &cfg = module.payload_variant.neighbor_info;
            view->updateNeighborInfoModule(cfg);
            break;
        }
        case meshtastic_ModuleConfig_ambient_lighting_tag: {
            const meshtastic_ModuleConfig_AmbientLightingConfig &cfg = module.payload_variant.ambient_lighting;
            view->updateAmbientLightingModule(cfg);
            break;
        }
        case meshtastic_ModuleConfig_detection_sensor_tag: {
            const meshtastic_ModuleConfig_DetectionSensorConfig &cfg = module.payload_variant.detection_sensor;
            view->updateDetectionSensorModule(cfg);
            break;
        }
        case meshtastic_ModuleConfig_paxcounter_tag: {
            const meshtastic_ModuleConfig_PaxcounterConfig &cfg = module.payload_variant.paxcounter;
            view->updatePaxCounterModule(cfg);
            break;
        }
        default:
            ILOG_ERROR("unsupported module config variant: %u\n", module.which_payload_variant);
            return false;
        }
        break;
    }
    case meshtastic_FromRadio_channel_tag: {
        const meshtastic_Channel &ch = from.channel;
        if (ch.has_settings) {
            view->updateChannelConfig(ch);
        }
        break;
    }
    case meshtastic_FromRadio_metadata_tag: {
        const meshtastic_DeviceMetadata &meta = from.metadata;
        view->setDeviceMetaData(meta.hw_model, meta.firmware_version, meta.hasBluetooth, meta.hasWifi, meta.hasEthernet,
                                meta.canShutdown);
        break;
    }
    case meshtastic_FromRadio_config_complete_id_tag: {
        view->configCompleted();
        requestAdditionalConfig();
        view->notifyResync(false);
        break;
    }
    case meshtastic_FromRadio_queueStatus_tag: {
        const meshtastic_QueueStatus &q = from.queueStatus;
        if (q.free == 0) {
            ILOG_CRIT("meshqueue full!?\n");
        }
        break;
    }
    case meshtastic_FromRadio_rebooted_tag: {
        view->notifyResync(true);
        setConfigRequested(true);
        break;
    }
    default: {
        ILOG_ERROR("unhandled fromRadio packet variant: %u\n", from.which_payload_variant);
        return false;
    }
    }
    return true;
}

bool ViewController::packetReceived(const meshtastic_MeshPacket &p)
{
    ILOG_DEBUG("received packet from 0x%08x(%u), portnum=%u\n", p.from, p.from, p.decoded.portnum);
    view->packetReceived(p);

    // only for direct neighbors print rssi/snr
    if (p.hop_limit == p.hop_start) {
        view->updateSignalStrength(p.from, p.rx_rssi, p.rx_snr);
    } else if (p.hop_start > 0) {
        view->updateHopsAway(p.from, p.hop_start - p.hop_limit);
    }
    view->updateLastHeard(p.from);

    switch (p.decoded.portnum) {
    case meshtastic_PortNum_TEXT_MESSAGE_APP: {
        ILOG_INFO("received text message from 0x%08x(%u): '%s'\n", p.from, p.from, (const char *)p.decoded.payload.bytes);
        view->newMessage(p.from, p.to, p.channel, (const char *)p.decoded.payload.bytes);
        break;
    }
    case meshtastic_PortNum_POSITION_APP: {
        meshtastic_Position position;
        if (pb_decode_from_bytes(p.decoded.payload.bytes, p.decoded.payload.size, &meshtastic_Position_msg, &position)) {
            view->updatePosition(p.from, position.latitude_i, position.longitude_i, position.altitude, position.sats_in_view,
                                 position.precision_bits);
            // TODO: updateTime(position.time);
        } else {
            ILOG_ERROR("Error decoding protobuf meshtastic_Position!\n");
            return false;
        }
        break;
    }
    case meshtastic_PortNum_NODEINFO_APP: {
        meshtastic_User user;
        if (pb_decode_from_bytes(p.decoded.payload.bytes, p.decoded.payload.size, &meshtastic_User_msg, &user)) {
            view->updateNode(p.from, -1, user.short_name, user.long_name, 0, (MeshtasticView::eRole)user.role,
                             false); // TODO viaMqtt?
        } else {
            ILOG_ERROR("Error decoding protobuf meshtastic_User (nodeinfo)!\n");
            return false;
        }
        break;
    }
    case meshtastic_PortNum_TELEMETRY_APP: {
        meshtastic_Telemetry telemetry;
        if (pb_decode_from_bytes(p.decoded.payload.bytes, p.decoded.payload.size, &meshtastic_Telemetry_msg, &telemetry)) {
            switch (telemetry.which_variant) {
            case meshtastic_Telemetry_device_metrics_tag: {
                view->updateMetrics(
                    p.from, telemetry.variant.device_metrics.battery_level, telemetry.variant.device_metrics.voltage,
                    telemetry.variant.device_metrics.channel_utilization, telemetry.variant.device_metrics.air_util_tx);
                break;
            }
            case meshtastic_Telemetry_environment_metrics_tag: {
                view->updateEnvironmentMetrics(p.from, telemetry.variant.environment_metrics);
                break;
            }
            case meshtastic_Telemetry_air_quality_metrics_tag: {
                view->updateAirQualityMetrics(p.from, telemetry.variant.air_quality_metrics);
                return false;
                break;
            }
            case meshtastic_Telemetry_power_metrics_tag: {
                view->updatePowerMetrics(p.from, telemetry.variant.power_metrics);
                return false;
                break;
            }
            default:
                ILOG_ERROR("unhandled telemetry variant: %u\n", telemetry.which_variant);
                return false;
                break;
            }
        } else {
            ILOG_ERROR("Error decoding protobuf meshtastic_Telemetry!\n");
            return false;
        }
        break;
    }
    case meshtastic_PortNum_ROUTING_APP:
        meshtastic_Routing routing;
        ILOG_DEBUG("PortNum_ROUTING_APP: id:%08x, from:%08x, to:%08x, dest:%08x, source:%08x, requestId:%08x, replyId:%08x\n",
                   p.id, p.from, p.to, p.decoded.dest, p.decoded.source, p.decoded.request_id, p.decoded.reply_id);
        if (pb_decode_from_bytes(p.decoded.payload.bytes, p.decoded.payload.size, &meshtastic_Routing_msg, &routing)) {
            if (routing.which_variant == meshtastic_Routing_error_reason_tag) {
                switch (routing.error_reason) {
                case meshtastic_Routing_Error_NONE:
                case meshtastic_Routing_Error_MAX_RETRANSMIT:
                    view->handleResponse(p.from, p.decoded.request_id, routing);
                    break;
                default:
                    ILOG_WARN("got unhandled Routing_Error: %d\n", routing.error_reason);
                    break;
                }
            } else {
                view->handleResponse(p.from, p.decoded.request_id, routing);
            }
        } else {
            ILOG_ERROR("Error decoding protobuf meshtastic_Routing!\n");
            return false;
        }
        break;
    case meshtastic_PortNum_ADMIN_APP: {
        meshtastic_AdminMessage admin;
        if (pb_decode_from_bytes(p.decoded.payload.bytes, p.decoded.payload.size, &meshtastic_AdminMessage_msg, &admin)) {
            switch (admin.which_payload_variant) {
            case meshtastic_AdminMessage_get_device_connection_status_response_tag: {
                meshtastic_DeviceConnectionStatus &status = admin.get_device_connection_status_response;
                view->updateConnectionStatus(status);
                break;
            }
            case meshtastic_AdminMessage_get_config_response_tag: {
                meshtastic_Config &config = admin.get_config_response;
                switch (config.which_payload_variant) {
                case meshtastic_Config_device_tag: {
                    const meshtastic_Config_DeviceConfig &cfg = config.payload_variant.device;
                    view->updateDeviceConfig(cfg);
                    break;
                }
                case meshtastic_Config_position_tag: {
                    const meshtastic_Config_PositionConfig &cfg = config.payload_variant.position;
                    view->updatePositionConfig(cfg);
                    break;
                }
                case meshtastic_Config_power_tag: {
                    const meshtastic_Config_PowerConfig &cfg = config.payload_variant.power;
                    view->updatePowerConfig(cfg);
                    break;
                }
                case meshtastic_Config_network_tag: {
                    const meshtastic_Config_NetworkConfig &cfg = config.payload_variant.network;
                    view->updateNetworkConfig(cfg);
                    break;
                }
                case meshtastic_Config_display_tag: {
                    const meshtastic_Config_DisplayConfig &cfg = config.payload_variant.display;
                    view->updateDisplayConfig(cfg);
                    break;
                }
                case meshtastic_Config_lora_tag: {
                    const meshtastic_Config_LoRaConfig &cfg = config.payload_variant.lora;
                    view->updateLoRaConfig(cfg);
                    break;
                }
                case meshtastic_Config_bluetooth_tag: {
                    const meshtastic_Config_BluetoothConfig &cfg = config.payload_variant.bluetooth;
                    view->updateBluetoothConfig(cfg);
                    break;
                }
                default:
                    ILOG_ERROR("unhandled meshtastic_Config variant: %u\n", config.which_payload_variant);
                }
                break;
            }
            case meshtastic_AdminMessage_get_module_config_response_tag: {
                meshtastic_ModuleConfig &config = admin.get_module_config_response;
                switch (config.which_payload_variant) {
                case meshtastic_ModuleConfig_mqtt_tag: {
                    const meshtastic_ModuleConfig_MQTTConfig &cfg = config.payload_variant.mqtt;
                    view->updateMQTTModule(cfg);
                    break;
                }
                default:
                    ILOG_ERROR("unhandled meshtastic_ModuleConfig variant: %u\n", config.which_payload_variant);
                }
                break;
            }
            case meshtastic_AdminMessage_get_ringtone_response_tag: {
                view->updateRingtone(admin.get_ringtone_response);
                break;
            }
            default:
                ILOG_ERROR("unhandled AdminMessage variant: %u\n", admin.which_payload_variant);
                return false;
                break;
            }
        } else {
            ILOG_ERROR("Error decoding protobuf meshtastic_AdminMessage!\n");
            return false;
        }
        break;
    }
    case meshtastic_PortNum_SIMULATOR_APP:
        break;
    default:
        ILOG_ERROR("unhandled meshpacket portnum: %u\n", p.decoded.portnum);
        return false;
    }
    return true;
}

ViewController::~ViewController() {}
