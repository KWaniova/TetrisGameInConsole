
#ifndef UNTITLED_CONFIG_H
#define UNTITLED_CONFIG_H

static constexpr int DEFAULT_CANVAS_HEIGHT = 15;
static constexpr int DEFAULT_CANVAS_WIDTH = 10;
static constexpr char DEFAULT_EMPTY_SYMBOL = ' ';

class Config {
     int CANVAS_HEIGHT = DEFAULT_CANVAS_HEIGHT;
     int CANVAS_WIDTH = DEFAULT_CANVAS_WIDTH;
     char EMPTY_SYMBOL = DEFAULT_EMPTY_SYMBOL;

    Config();
    Config(Config const&) = delete;
    Config& operator=(Config const&) = delete;
public:
    using empty_point_type = char;


    static Config& get_instance() {
        static Config instance;
        return instance;
    }

    int get_default_canvas_height();
    int get_default_canvas_width();
    char get_default_empty_symbol();

    void set_default_canvas_height(int height);
    void set_default_canvas_width(int width);
    void set_default_empty_symbol(char empty_symbol);

    void reset_config_state();

};


#endif //UNTITLED_GAME_SYSTEM_H
