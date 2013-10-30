const uint8_t PROGMEM m_full_teeth0[] =
        { B00000000,
          B00000000,
          B00000000,
          B00000000,
          B00000000,
          B00000000,
          B00000000,
          B00000000 };

const uint8_t PROGMEM m_full_teeth1[] =
        { B11111111,
          B00000000,
          B00000000,
          B00000000,
          B00000000,
          B00000000,
          B00000000,
          B11111111 };

const uint8_t PROGMEM m_full_teeth2[] =
        { B11111111,
          B11111111,
          B00000000,
          B00000000,
          B00000000,
          B00000000,
          B11111111,
          B11111111 };

const uint8_t PROGMEM m_full_teeth3[] =
        { B11111111,
          B11111111,
          B11111111,
          B00000000,
          B00000000,
          B11111111,
          B11111111,
          B11111111 };

const uint8_t PROGMEM m_full_teeth4[] =
        { B11111111,
          B11111111,
          B11111111,
          B11111111,
          B11111111,
          B11111111,
          B11111111,
          B11111111 };

const uint8_t PROGMEM evilgrin0[] =
        { B11111111,
          B11111111,
          B11111111,
          B11111111,
          B00000000,
          B11111111,
          B11111111,
          B11111111 };

const uint8_t PROGMEM evilgrin1[] =
        { B11111111,
          B11111111,
          B11111111,
          B01111110,
          B10000001,
          B11111111,
          B11111111,
          B11111111 };

const uint8_t PROGMEM evilgrin2[] =
        { B11111111,
          B11111111,
          B01111110,
          B10111101,
          B11000011,
          B11111111,
          B11111111,
          B11111111 };

const uint8_t PROGMEM evilgrin3[] =
        { B11111111,
          B01111110,
          B10111101,
          B11011011,
          B11100111,
          B11111111,
          B11111111,
          B11111111 };

const uint8_t PROGMEM evilgrin4[] =
        { B11111111,
          B01111110,
          B10111101,
          B11011011,
          B11100111,
          B11111111,
          B11111111,
          B11111111 };

const uint8_t PROGMEM beak0[] =
        { B00011000,
          B00000000,
          B00000000,
          B00000000,
          B00000000,
          B00000000,
          B00000000,
          B00000000 };

const uint8_t PROGMEM beak1[] =
        { B00011000,
          B00011000,
          B00000000,
          B00000000,
          B00000000,
          B00000000,
          B00000000,
          B11000011 };

const uint8_t PROGMEM beak2[] =
        { B00111100,
          B00011000,
          B00011000,
          B00000000,
          B00000000,
          B00000000,
          B11000011,
          B11100111 };

const uint8_t PROGMEM beak3[] =
        { B11111111,
          B00111100,
          B00011000,
          B00011000,
          B00000000,
          B11000011,
          B11100111,
          B11100111 };

const uint8_t PROGMEM beak4[] =
        { B11111111,
          B11111111,
          B00111100,
          B00011000,
          B11011011,
          B11100111,
          B11100111,
          B11111111 };

const uint8_t PROGMEM beak5[] =
        { B11111111,
          B11111111,
          B11111111,
          B00111100,
          B11011011,
          B11111111,
          B11100111,
          B11111111 };

const uint8_t PROGMEM beak6[] =
        { B11111111,
          B11111111,
          B11111111,
          B11111111,
          B11111111,
          B11111111,
          B11111111,
          B11111111 };

PROGMEM const uint8_t *chomp_anim[] = 
    {
        m_full_teeth0,
        m_full_teeth1,
        m_full_teeth2,
        m_full_teeth3,
        m_full_teeth4
    };

PROGMEM const uint8_t *evilgrin_anim[] = 
    {
        evilgrin0,
        evilgrin1,
        evilgrin2,
        evilgrin3,
        evilgrin4
    };

PROGMEM const uint8_t *beak_anim[] = 
    {
        beak0,
        beak1,
        beak2,
        beak3,
        beak4,
        beak5,
        beak6
    };
