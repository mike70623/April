
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <cmath>
#include <iostream>
using namespace std;

class Brick {
private:
	int width;
	int height;
	int xPosition;
	int yPosition;
	int dead;
public:
	void constructor();
	void initBrick(int w, int h, int x, int y);
	void draw();
	bool isDead();
	void killBrick();
	bool collision(int ball_x, int ball_y, int ball_w, int ball_h);
	bool collision2(int ball2_x, int ball2_y, int ball2_w, int ball2_h);

};

bool collision(int ball_x, int ball_y, int ball_w, int ball_h, int paddle_x, int paddle_y, int paddle_w, int paddle_h);
bool collision2(int ball2_x, int ball2_y, int ball2_w, int ball2_h, int paddle_x, int paddle_y, int paddle_w, int paddle_h);

int main(int argc, char **argv) {
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *square = NULL;
	ALLEGRO_BITMAP *ball = NULL;
	ALLEGRO_BITMAP *ball2 = NULL;
	ALLEGRO_SAMPLE *sample1 = NULL;
	ALLEGRO_SAMPLE *sample2 = NULL;
	ALLEGRO_SAMPLE *sample3 = NULL;
	ALLEGRO_SAMPLE_INSTANCE *instance1 = NULL;
	ALLEGRO_SAMPLE_INSTANCE *instance2 = NULL;
	srand(time(NULL));

	float square_x = 340;
	float square_y = 776;
	int ball_x = 390;
	int ball_y = 390;
	int ball2_x = 390;
	int ball2_y = 390;

	float ball_dx = -1.5, ball_dy = 3.0;
	float ball2_dx = -1.5, ball2_dy = 3.0;
	int score1 = 0;
	int rand1 = rand() % 10 + 1;

	bool key[2] = { false, false };
	bool redraw = true;
	bool doexit = false;
	cout << "flag1" << endl;
	al_init();
	al_init_primitives_addon();
	al_install_keyboard();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_audio();
	al_init_acodec_addon();
	//ALLEGRO_FONT *font = al_load_ttf_font("AlexBrush.ttf", 72, 0);
	timer = al_create_timer(.01);

	//al_reserve_samples(10);
	//sample1 = al_load_sample("boing.wav");
	//sample2 = al_load_sample("northlane.wav");
	//instance1 = al_create_sample_instance(sample1);
	//instance2 = al_create_sample_instance(sample2);
	//al_set_sample_instance_playmode(instance2, ALLEGRO_PLAYMODE_LOOP);
	//al_attach_sample_instance_to_mixer(instance1, al_get_default_mixer());
	//al_attach_sample_instance_to_mixer(instance2, al_get_default_mixer());
	//al_play_sample_instance(instance2);

	cout << "flag1.2" << endl;
	display = al_create_display(800, 800);
	square = al_create_bitmap(120, 20);
	ball = al_create_bitmap(20, 20);
	ball2 = al_create_bitmap(20, 20);

	cout << "flag2" << endl;
	al_set_target_bitmap(square);
	al_clear_to_color(al_map_rgb(255, 0, 0));
	al_set_target_bitmap(ball);
	al_clear_to_color(al_map_rgb(0, 255, 255));
	al_set_target_bitmap(ball2);
	al_clear_to_color(al_map_rgb(67, 255, 255));
	al_set_target_bitmap(al_get_backbuffer(display));

	cout << "flag3" << endl;
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_clear_to_color(al_map_rgb(34, 5, 87));
	al_flip_display();
	al_start_timer(timer);
	cout << "flag4" << endl;

	Brick brick1;
	brick1.initBrick(142, 30, 15, 120);
	Brick brick2;
	brick2.initBrick(142, 30, 172, 120);
	Brick brick3;
	brick3.initBrick(142, 30, 329, 120);
	Brick brick4;
	brick4.initBrick(142, 30, 486, 120);
	Brick brick5;
	brick5.initBrick(142, 30, 643, 120);
	Brick brick6;
	brick6.initBrick(142, 30, 15, 165);
	Brick brick7;
	brick7.initBrick(142, 30, 172, 165);
	Brick brick8;
	brick8.initBrick(142, 30, 329, 165);
	Brick brick9;
	brick9.initBrick(142, 30, 486, 165);
	Brick brick10;
	brick10.initBrick(142, 30, 643, 165);
	Brick brick11;
	brick11.initBrick(142, 30, 15, 210);
	Brick brick12;
	brick12.initBrick(142, 30, 172, 210);
	Brick brick13;
	brick13.initBrick(142, 30, 329, 210);
	Brick brick14;
	brick14.initBrick(142, 30, 486, 210);
	Brick brick15;
	brick15.initBrick(142, 30, 643, 210);
	Brick brick16;
	brick16.initBrick(142, 30, 15, 255);
	Brick brick17;
	brick17.initBrick(142, 30, 172, 255);
	Brick brick18;
	brick18.initBrick(142, 30, 329, 255);
	Brick brick19;
	brick19.initBrick(142, 30, 486, 255);
	Brick brick20;
	brick20.initBrick(142, 30, 643, 255);
	Brick brick21;
	brick21.initBrick(142, 30, 15, 300);
	Brick brick22;
	brick22.initBrick(142, 30, 172, 300);
	Brick brick23;
	brick23.initBrick(142, 30, 329, 300);
	Brick brick24;
	brick24.initBrick(142, 30, 486, 300);
	Brick brick25;
	brick25.initBrick(142, 30, 643, 300);
	Brick brick26;
	brick26.initBrick(142, 30, 15, 345);
	Brick brick27;
	brick27.initBrick(142, 30, 172, 345);
	Brick brick28;
	brick28.initBrick(142, 30, 329, 345);
	Brick brick29;
	brick29.initBrick(142, 30, 486, 345);
	Brick brick30;
	brick30.initBrick(142, 30, 643, 345);

	while (!doexit) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_TIMER) {//////////////////////////////////////////////////////
											 //if the box hits the left wall OR the right wall
			if (ball_x < 0 || ball_x > 800 - 20) {
				//flip the x direction
				ball_dx = -ball_dx;
			}
			//if the box hits the top wall OR the bottom wall
			if (ball_y < 0 || ball_y > 800 - 20) {
				//flip the y direction
				ball_dy = -ball_dy;
			}
			if (ball2_x < 0 || ball2_x > 800 - 20) {
				//flip the x direction
				ball2_dx = -ball2_dx;
			}
			//if the box hits the top wall OR the bottom wall
			if (ball2_y < 0 || ball2_y > 800 - 20) {
				//flip the y direction
				ball2_dy = -ball2_dy;
			}
			if (rand1 % 2 == 0)
				ball_x += ball_dx;
			else
				ball_x += -ball_dx;
			ball_y += ball_dy;

			ball2_x += -ball2_dx;
			ball2_y += ball2_dy;

			if (key[0] && square_x >= 1) {//left
				square_x -= 4.0;
			}
			if (key[1] && square_x <= 800 - 121) {//right
				square_x += 4.0;
			}

			//call collision function, if true, flip ball x & y
			int rand2 = rand() % 10 + 1;
			if (collision(ball_x, ball_y, 20, 20, square_x, square_y, 120, 20) == 1) {
				//al_play_sample_instance(instance1);
				ball_dy = -ball_dy;
				if (rand2 % 2 == 0)
					ball_dx = -ball_dx;
				else
					ball_dx = ball_dx;
			}
				if (collision(ball2_x, ball2_y, 20, 20, square_x, square_y, 120, 20) == 1) {
					//al_play_sample_instance(instance1);
					ball2_dy = -ball2_dy;
					if (rand2 % 2 == 0)
						ball2_dx = -ball2_dx;
					else
						ball2_dx = ball2_dx;
				//cool sound effect goes here
			}
			int randR = rand() % 10 + 1;
			if (ball_y >= 775) {
				ball_x = 390, ball_y = 390;
				if (randR % 2 == 0)
					ball_dx = -ball_dx;
				else
					ball_dx = ball_dx;
			}
			if (ball2_y >= 775) {
				ball2_x = 390, ball2_y = 390;
				if (randR % 2 == 0)
					ball2_dx = -ball2_dx;
				else
					ball2_dx = ball2_dx;
			}
			//brick collision section
			if ((brick1.collision(ball2_x, ball2_y, 20, 20) == 1) && brick1.isDead() == 0) {
				//play annoying sound effect here
				ball2_dx = -ball2_dx;
				ball2_dy = -ball2_dy;

				brick1.killBrick();
			}
			if ((brick2.collision(ball2_x, ball2_y, 20, 20) == 1) && brick2.isDead() == 0) {
				//play annoying sound effect here
				ball2_dx = -ball2_dx;
				ball2_dy = -ball2_dy;

				brick2.killBrick();
			}
			if ((brick3.collision(ball2_x, ball2_y, 20, 20) == 1) && brick3.isDead() == 0) {
				//play annoying sound effect here
				ball2_dx = -ball2_dx;
				ball2_dy = -ball2_dy;

				brick3.killBrick();
			}
			if ((brick4.collision(ball2_x, ball2_y, 20, 20) == 1) && brick4.isDead() == 0) {
				//play annoying sound effect here
				ball2_dx = -ball2_dx;
				ball2_dy = -ball2_dy;

				brick4.killBrick();
			}
			if ((brick5.collision(ball2_x, ball2_y, 20, 20) == 1) && brick5.isDead() == 0) {
				//play annoying sound effect here
				ball2_dx = -ball2_dx;
				ball2_dy = -ball2_dy;

				brick5.killBrick();
			}
			if ((brick6.collision(ball2_x, ball2_y, 20, 20) == 1) && brick6.isDead() == 0) {
				//play annoying sound effect here
				ball2_dx = -ball2_dx;
				ball2_dy = -ball2_dy;

				brick6.killBrick();
			}
			if ((brick7.collision(ball2_x, ball2_y, 20, 20) == 1) && brick7.isDead() == 0) {
				//play annoying sound effect here
				ball2_dx = -ball2_dx;
				ball2_dy = -ball2_dy;

				brick7.killBrick();
			}
			if ((brick8.collision(ball2_x, ball2_y, 20, 20) == 1) && brick8.isDead() == 0) {
				//play annoying sound effect here
				ball2_dx = -ball2_dx;
				ball2_dy = -ball2_dy;

				brick8.killBrick();
			}
			if ((brick9.collision(ball2_x, ball2_y, 20, 20) == 1) && brick9.isDead() == 0) {
				//play annoying sound effect here
				ball2_dx = -ball2_dx;
				ball2_dy = -ball2_dy;

				brick9.killBrick();
			}
			if ((brick10.collision(ball2_x, ball2_y, 20, 20) == 1) && brick10.isDead() == 0) {
				//play annoying sound effect here
				ball2_dx = -ball2_dx;
				ball2_dy = -ball2_dy;

				brick10.killBrick();
			}
			if ((brick11.collision(ball2_x, ball2_y, 20, 20) == 1) && brick11.isDead() == 0) {
				//play annoying sound effect here
				ball2_dx = -ball2_dx;
				ball2_dy = -ball2_dy;

				brick11.killBrick();
			}
			if ((brick12.collision(ball2_x, ball2_y, 20, 20) == 1) && brick12.isDead() == 0) {
				//play annoying sound effect here
				ball2_dx = -ball2_dx;
				ball2_dy = -ball2_dy;

				brick12.killBrick();
			}
			if ((brick13.collision(ball2_x, ball2_y, 20, 20) == 1) && brick13.isDead() == 0) {
				//play annoying sound effect here
				ball2_dx = -ball2_dx;
				ball2_dy = -ball2_dy;

				brick13.killBrick();
			}
			if ((brick14.collision(ball2_x, ball2_y, 20, 20) == 1) && brick14.isDead() == 0) {
				//play annoying sound effect here
				ball2_dx = -ball2_dx;
				ball2_dy = -ball2_dy;

				brick14.killBrick();
			}
			if ((brick15.collision(ball2_x, ball2_y, 20, 20) == 1) && brick15.isDead() == 0) {
				//play annoying sound effect here
				ball2_dx = -ball2_dx;
				ball2_dy = -ball2_dy;

				brick15.killBrick();
			}
			if ((brick16.collision(ball2_x, ball2_y, 20, 20) == 1) && brick16.isDead() == 0) {
				//play annoying sound effect here
				ball2_dx = -ball2_dx;
				ball2_dy = -ball2_dy;

				brick16.killBrick();
			}
			if ((brick17.collision(ball2_x, ball2_y, 20, 20) == 1) && brick17.isDead() == 0) {
				//play annoying sound effect here
				ball2_dx = -ball2_dx;
				ball2_dy = -ball2_dy;

				brick17.killBrick();
			}
			if ((brick18.collision(ball2_x, ball2_y, 20, 20) == 1) && brick18.isDead() == 0) {
				//play annoying sound effect here
				ball2_dx = -ball2_dx;
				ball2_dy = -ball2_dy;

				brick18.killBrick();
			}
			if ((brick19.collision(ball2_x, ball2_y, 20, 20) == 1) && brick19.isDead() == 0) {
				//play annoying sound effect here
				ball2_dx = -ball2_dx;
				ball2_dy = -ball2_dy;

				brick19.killBrick();
			}
			if ((brick20.collision(ball2_x, ball2_y, 20, 20) == 1) && brick20.isDead() == 0) {
				//play annoying sound effect here
				ball2_dx = -ball2_dx;
				ball2_dy = -ball2_dy;

				brick20.killBrick();
			}
			if ((brick21.collision(ball2_x, ball2_y, 20, 20) == 1) && brick21.isDead() == 0) {
				//play annoying sound effect here
				ball2_dx = -ball2_dx;
				ball2_dy = -ball2_dy;

				brick21.killBrick();
			}
			if ((brick22.collision(ball2_x, ball2_y, 20, 20) == 1) && brick22.isDead() == 0) {
				//play annoying sound effect here
				ball2_dx = -ball2_dx;
				ball2_dy = -ball2_dy;

				brick22.killBrick();
			}
			if ((brick23.collision(ball2_x, ball2_y, 20, 20) == 1) && brick23.isDead() == 0) {
				//play annoying sound effect here
				ball2_dx = -ball2_dx;
				ball2_dy = -ball2_dy;

				brick23.killBrick();
			}
			if ((brick24.collision(ball2_x, ball2_y, 20, 20) == 1) && brick24.isDead() == 0) {
				//play annoying sound effect here
				ball2_dx = -ball2_dx;
				ball2_dy = -ball2_dy;

				brick24.killBrick();
			}
			if ((brick25.collision(ball2_x, ball2_y, 20, 20) == 1) && brick25.isDead() == 0) {
				//play annoying sound effect here
				ball2_dx = -ball2_dx;
				ball2_dy = -ball2_dy;

				brick25.killBrick();
			}
			if ((brick26.collision(ball2_x, ball2_y, 20, 20) == 1) && brick26.isDead() == 0) {
				//play annoying sound effect here
				ball2_dx = -ball2_dx;
				ball2_dy = -ball2_dy;

				brick26.killBrick();
			}
			if ((brick27.collision(ball2_x, ball2_y, 20, 20) == 1) && brick27.isDead() == 0) {
				//play annoying sound effect here
				ball2_dx = -ball2_dx;
				ball2_dy = -ball2_dy;

				brick27.killBrick();
			}
			if ((brick28.collision(ball2_x, ball2_y, 20, 20) == 1) && brick28.isDead() == 0) {
				//play annoying sound effect here
				ball2_dx = -ball2_dx;
				ball2_dy = -ball2_dy;

				brick28.killBrick();
			}
			if ((brick29.collision(ball2_x, ball2_y, 20, 20) == 1) && brick29.isDead() == 0) {
				//play annoying sound effect here
				ball2_dx = -ball2_dx;
				ball2_dy = -ball2_dy;

				brick29.killBrick();
			}
			if ((brick30.collision(ball2_x, ball2_y, 20, 20) == 1) && brick30.isDead() == 0) {
				//play annoying sound effect here
				ball2_dx = -ball2_dx;
				ball2_dy = -ball2_dy;

				brick30.killBrick();
			}
			//brick collision section
			if ((brick1.collision(ball_x, ball_y, 20, 20) == 1) && brick1.isDead() == 0) {
				//play annoying sound effect here
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
				
				brick1.killBrick();
			}
			if ((brick2.collision(ball_x, ball_y, 20, 20) == 1) && brick2.isDead() == 0) {
				//play annoying sound effect here
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
				
				brick2.killBrick();
			}
			if ((brick3.collision(ball_x, ball_y, 20, 20) == 1) && brick3.isDead() == 0) {
				//play annoying sound effect here
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
				
				brick3.killBrick();
			}
			if ((brick4.collision(ball_x, ball_y, 20, 20) == 1) && brick4.isDead() == 0) {
				//play annoying sound effect here
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
				
				brick4.killBrick();
			}
			if ((brick5.collision(ball_x, ball_y, 20, 20) == 1) && brick5.isDead() == 0) {
				//play annoying sound effect here
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
				
				brick5.killBrick();
			}
			if ((brick6.collision(ball_x, ball_y, 20, 20) == 1) && brick6.isDead() == 0) {
				//play annoying sound effect here
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
				
				brick6.killBrick();
			}
			if ((brick7.collision(ball_x, ball_y, 20, 20) == 1) && brick7.isDead() == 0) {
				//play annoying sound effect here
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
				
				brick7.killBrick();
			}
			if ((brick8.collision(ball_x, ball_y, 20, 20) == 1) && brick8.isDead() == 0) {
				//play annoying sound effect here
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
				
				brick8.killBrick();
			}
			if ((brick9.collision(ball_x, ball_y, 20, 20) == 1) && brick9.isDead() == 0) {
				//play annoying sound effect here
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
				
				brick9.killBrick();
			}
			if ((brick10.collision(ball_x, ball_y, 20, 20) == 1) && brick10.isDead() == 0) {
				//play annoying sound effect here
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
				
				brick10.killBrick();
			}
			if ((brick11.collision(ball_x, ball_y, 20, 20) == 1) && brick11.isDead() == 0) {
				//play annoying sound effect here
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
				
				brick11.killBrick();
			}
			if ((brick12.collision(ball_x, ball_y, 20, 20) == 1) && brick12.isDead() == 0) {
				//play annoying sound effect here
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
				
				brick12.killBrick();
			}
			if ((brick13.collision(ball_x, ball_y, 20, 20) == 1) && brick13.isDead() == 0) {
				//play annoying sound effect here
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
				
				brick13.killBrick();
			}
			if ((brick14.collision(ball_x, ball_y, 20, 20) == 1) && brick14.isDead() == 0) {
				//play annoying sound effect here
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
			
				brick14.killBrick();
			}
			if ((brick15.collision(ball_x, ball_y, 20, 20) == 1) && brick15.isDead() == 0) {
				//play annoying sound effect here
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
			
				brick15.killBrick();
			}
			if ((brick16.collision(ball_x, ball_y, 20, 20) == 1) && brick16.isDead() == 0) {
				//play annoying sound effect here
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
			
				brick16.killBrick();
			}
			if ((brick17.collision(ball_x, ball_y, 20, 20) == 1) && brick17.isDead() == 0) {
				//play annoying sound effect here
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
				
				brick17.killBrick();
			}
			if ((brick18.collision(ball_x, ball_y, 20, 20) == 1) && brick18.isDead() == 0) {
				//play annoying sound effect here
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
			
				brick18.killBrick();
			}
			if ((brick19.collision(ball_x, ball_y, 20, 20) == 1) && brick19.isDead() == 0) {
				//play annoying sound effect here
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
			
				brick19.killBrick();
			}
			if ((brick20.collision(ball_x, ball_y, 20, 20) == 1) && brick20.isDead() == 0) {
				//play annoying sound effect here
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
			
				brick20.killBrick();
			}
			if ((brick21.collision(ball_x, ball_y, 20, 20) == 1) && brick21.isDead() == 0) {
				//play annoying sound effect here
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
		
				brick21.killBrick();
			}
			if ((brick22.collision(ball_x, ball_y, 20, 20) == 1) && brick22.isDead() == 0) {
				//play annoying sound effect here
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
	
				brick22.killBrick();
			}
			if ((brick23.collision(ball_x, ball_y, 20, 20) == 1) && brick23.isDead() == 0) {
				//play annoying sound effect here
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
		
				brick23.killBrick();
			}
			if ((brick24.collision(ball_x, ball_y, 20, 20) == 1) && brick24.isDead() == 0) {
				//play annoying sound effect here
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
			
				brick24.killBrick();
			}
			if ((brick25.collision(ball_x, ball_y, 20, 20) == 1) && brick25.isDead() == 0) {
				//play annoying sound effect here
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
			
				brick25.killBrick();
			}
			if ((brick26.collision(ball_x, ball_y, 20, 20) == 1) && brick26.isDead() == 0) {
				//play annoying sound effect here
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
			
				brick26.killBrick();
			}
			if ((brick27.collision(ball_x, ball_y, 20, 20) == 1) && brick27.isDead() == 0) {
				//play annoying sound effect here
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
			
				brick27.killBrick();
			}
			if ((brick28.collision(ball_x, ball_y, 20, 20) == 1) && brick28.isDead() == 0) {
				//play annoying sound effect here
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
			
				brick28.killBrick();
			}
			if ((brick29.collision(ball_x, ball_y, 20, 20) == 1) && brick29.isDead() == 0) {
				//play annoying sound effect here
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
			
				brick29.killBrick();
			}
			if ((brick30.collision(ball_x, ball_y, 20, 20) == 1) && brick30.isDead() == 0) {
				//play annoying sound effect here
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
				
				brick30.killBrick();
			}

			redraw = true;
		}//end timer//////////////////////////////////////////////////////////////////////////////
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_A:
				key[0] = true;
				break;
			case ALLEGRO_KEY_D:
				key[1] = true;
				break;
			}
		}//end key down
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_A:
				key[0] = false;
				break;
			case ALLEGRO_KEY_D:
				key[1] = false;
				break;
			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}
		}//end key up
		 //render section
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));

			if (brick1.isDead() == 0)
				brick1.draw();
			if (brick2.isDead() == 0)
				brick2.draw();
			if (brick3.isDead() == 0)
				brick3.draw();
			if (brick4.isDead() == 0)
				brick4.draw();
			if (brick5.isDead() == 0)
				brick5.draw();
			if (brick6.isDead() == 0)
				brick6.draw();
			if (brick7.isDead() == 0)
				brick7.draw();
			if (brick8.isDead() == 0)
				brick8.draw();
			if (brick9.isDead() == 0)
				brick9.draw();
			if (brick10.isDead() == 0)
				brick10.draw();
			if (brick11.isDead() == 0)
				brick11.draw();
			if (brick12.isDead() == 0)
				brick12.draw();
			if (brick13.isDead() == 0)
				brick13.draw();
			if (brick14.isDead() == 0)
				brick14.draw();
			if (brick15.isDead() == 0)
				brick15.draw();
			if (brick16.isDead() == 0)
				brick16.draw();
			if (brick17.isDead() == 0)
				brick17.draw();
			if (brick18.isDead() == 0)
				brick18.draw();
			if (brick19.isDead() == 0)
				brick19.draw();
			if (brick20.isDead() == 0)
				brick20.draw();
			if (brick21.isDead() == 0)
				brick21.draw();
			if (brick22.isDead() == 0)
				brick22.draw();
			if (brick23.isDead() == 0)
				brick23.draw();
			if (brick24.isDead() == 0)
				brick24.draw();
			if (brick25.isDead() == 0)
				brick25.draw();
			if (brick26.isDead() == 0)
				brick26.draw();
			if (brick27.isDead() == 0)
				brick27.draw();
			if (brick28.isDead() == 0)
				brick28.draw();
			if (brick29.isDead() == 0)
				brick29.draw();
			if (brick30.isDead() == 0)
				brick30.draw();

			al_draw_bitmap(square, square_x, square_y, 0);
			al_draw_bitmap(ball, ball_x, ball_y, 0);
			al_draw_bitmap(ball2, ball2_x, ball2_y, 0);
			//al_draw_text(font, al_map_rgb(0, 0, 255), 385, 40, ALLEGRO_ALIGN_CENTRE, "Breakout");
			//al_draw_textf(font, al_map_rgb(0, 255, 0), 700, 40, ALLEGRO_ALIGN_CENTRE, "%d", score1);
			al_flip_display();
		}
	}//end game loop

	al_destroy_sample_instance(instance2);
	al_destroy_sample(sample2);
	al_destroy_sample_instance(instance1);
	al_destroy_sample(sample1);
	al_destroy_bitmap(square);
	al_destroy_bitmap(ball);
	al_destroy_bitmap(ball2);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	return 0;
}

bool collision(int ball_x, int ball_y, int ball_w, int ball_h, int paddle_x, int paddle_y, int paddle_w, int paddle_h) {
	if ((ball_x > paddle_x + paddle_w) ||
		(ball_y > paddle_y + paddle_h) ||
		(ball_x + ball_w < paddle_x) ||
		(ball_y + ball_h < paddle_y))
		return 0;
	else
		return 1;
}

void Brick::constructor() {
	width = 0;
	height = 0;
	xPosition = 0;
	yPosition = 0;
	dead = 0;
}
void Brick::initBrick(int w, int h, int x, int y) {
	width = w;
	height = h;
	xPosition = x;
	yPosition = y;
	dead = 0;
}
void Brick::draw() {
	al_draw_filled_rectangle(xPosition, yPosition, xPosition + width, yPosition + height, al_map_rgb(255, 0, 155));
}
bool Brick::isDead() {
	return dead;
}
void Brick::killBrick() {
	dead = 1;
}

bool Brick::collision(int ball_x, int ball_y, int ball_w, int ball_h) {
	if ((ball_x > xPosition + width) ||
		(ball_y > yPosition + height) ||
		(ball_x + ball_w < xPosition) ||
		(ball_y + ball_h < yPosition))
		return 0;
	else
		return 1;

}
