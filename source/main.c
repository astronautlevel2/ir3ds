#include <3ds.h>
#include <stdio.h>

int drawPixel(int x, int y, char r, char g, char b, u8* screen, u32 height);
int printUsers();

int main(int argc, char **argv)
{
	gfxInitDefault();

	PrintConsole mainWindow, userlistWindow;
	
	consoleInit(GFX_TOP, &mainWindow);
	consoleInit(GFX_BOTTOM, &userlistWindow);
		
	consoleSetWindow(&userlistWindow, 30, 1, 20, 28);

	consoleSelect(&mainWindow);
	printf("\x1b[2;2HThis is where I'd print my buffer, if I had one");
	printf("\x1b[29;15HPress Start to lenny.");

	while (aptMainLoop())
	{

		consoleSelect(&userlistWindow);
		printUsers();

		hidScanInput();
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START) break;

		gfxFlushBuffers();
		gfxSwapBuffers();

		gspWaitForVBlank();
	}

	gfxExit();
	
	return 0;
}


int drawPixel(int x, int y, char r, char g, char b, u8* screen, u32 height)
{	// Default height for both screens is 240, but maybe we need to change that eventually
	// if we are going to draw anything out on the screen, we'll need that
	u32 v=(height-1-y+x*height)*3;
	screen[v]=b;
	screen[v+1]=g;
	screen[v+2]=r;
	
	return 0;
}

int printUsers()
{
	int userCount; // just a placeholder, don't look at me like that, I'm toying with consoles
	
	printf("\x1b[0;0H");
	for(userCount = 0; userCount < 5; userCount++)
	{
		printf("User\n");
	}

	return 0;
}
