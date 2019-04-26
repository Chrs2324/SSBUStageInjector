#include <string.h>
#include <stdio.h>

#include <switch.h>

int stageArray[100000];

int main(int argc, char **argv)
{
    gfxInitDefault();

    //Initialize console. Using NULL as the second argument tells the console library to use the internal console structure as current one.
    consoleInit(NULL);
	mkdir("sdmc:/Smash Maps");
    //Move the cursor to row 16 and column 20 and then prints "Hello World!"
    //To move the cursor you have to print "\x1b[r;cH", where r and c are respectively
    //the row and column where you want your cursor to move
    printf("\x1b[0;0HWelcome to Smash Map Injector! To install your maps, make sure you have you map files in the /maps folder on your SD Card!");
	printf("\x1b[4;0HAll files will automatically get moved to your save data!");
	printf("\x1b[8;0HMake sure your save folder is named 'smash_stages' for this to work!");
	printf("\x1b[12;0HTo exit out of application, press the '+' button");
	for (int i = 0; i <= 100000; i++)
	{
		char dir[1000] = "sdmc:/Smash Maps/stage_";
		char header[100000];
		itoa(i, header, 10);
		char fileHeader[10] = ".bin";
		char dir2[1000] = "sdmc:/switch/Checkpoint/saves/0x01006A800016E000 Super Smash Bros  Ultimate/smash_stages/save_data/stage/stage_";
		char header2[100000];
		itoa(i, header2, 10);
		char fileHeader2[10] = ".bin";
		strcat(header, fileHeader);
		strcat(dir, header);
		strcat(header2, fileHeader2);
		strcat(dir2, header2);
		rename(dir, dir2);
	}
	
	//rename("sdmc:/Smash Maps/stage.bin", "sdmc:/switch/Checkpoint/saves/0x01006A800016E000 Super Smash Bros  Ultimate/smash_stages/save_data/stage/stage.bin");
    while(appletMainLoop() && !(hidKeysDown(CONTROLLER_P1_AUTO) & KEY_PLUS))
    {
        //Scan all the inputs. This should be done once for each frame
        hidScanInput();

        //hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
		u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);

        if (kDown & KEY_PLUS) break; // break in order to return to hbmenu

        gfxFlushBuffers();
        gfxSwapBuffers();
        gfxWaitForVsync();
    }

    gfxExit();
    return 0;
}

