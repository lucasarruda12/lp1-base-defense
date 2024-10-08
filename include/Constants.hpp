// Window-related constants
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_BACKGROUND_COLOR sf::Color::Black

// Player-related constants
#define PLAYER_SPEED 5
#define PLAYER_SPAWN_X WINDOW_WIDTH/2
#define PLAYER_SPAWN_Y WINDOW_HEIGHT/2
#define PLAYER_HITBOX_RADIUS 12
#define PLAYER_MAX_AMMO 20
#define PLAYER_MIN_AMMO 0
#define PLAYER_MAX_HEALTH 20
#define PLAYER_MIN_HEALTH 0

// EnemyDropd-related constants
#define ENEMYDROP_HITBOX_RADIUS 3
#define ENEMYDROP_LIFETIME 300
#define AMMOBOX_RELOAD_AMMOUNT 5
#define HEALTHPACK_HEAL_AMMOUNT 2

// Bullet-related constants
#define BULLET_HITBOX_RADIUS 3
#define BULLET_SPEED 10
#define BULLET_LIFETIME 60

// Enemy-related constants
#define ENEMY_HITBOX_RADIUS 10
#define ENEMY_SPEED 1
#define ENEMY_SHOOTTIMER 45
#define ENEMY_SPAWN_TIMER 120
#define MAX_ENEMY_COUNT 6

// Base-related constants
#define BASE_MAX_HEALTH 20
#define BASE_RADIUS 64
#define BASE_HEALTH_REGEN_TIMER 60
#define BASE_HEALTH_REGEN_COOLDOWN_TIMER 180

// UserInterface-related constants
#define UI_WIDTH 200
#define UI_HEIGHT 20
#define UI_LEFT_MARGIN 20
#define UI_TOP_MARGIN 20
#define UI_OUTLINE_THICKNESS 2
#define UI_AMMO_BAR_VERTICAL_OFFSET 10
#define UI_BASE_HEALTH_VERTICAL_OFFSET 30
