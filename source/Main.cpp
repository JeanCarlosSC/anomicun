// Main.cpp - initialization using pointers to global objects
//
// A useful macro
#define SAFE_DELETE(p) {if(p) {delete(p); (p) = NULL}}

DataFiles*gp_DataFiles = NULL;
AudioSystem*gp_AudioSystem = NULL;
VideoSystem*gp_VideoSystem = NULL;

int main(void)
{
    gp_DataFiles = new DataFiles();
    if(NULL == gp_DataFiles || !gp_DataFiles->Initialized())
    {
        printf("The data files are somehow screwed.");
        return 1;
    }

    gp_AudioSystem = new AudioSystem();
    if(NULL == gp_AudioSystem || !gp_AudioSystem->Initialized())
    {
        printf("The audio system is somehow screwed.");
        return 1;
    }

    gp_VideoSystem = new VideoSystem();
    if(NULL == gp_VideoSystem || !gp_VideoSystem->Initialized())
    {
        printf("The video system is screwed.");
        return 1;
    }

    bool done = false;
    while (! done)
    {
        // imagine a cool main loop here
    }

    SAFE_DELETE(gp_VideoSystem);
    SAFE_DELETE(gp_AudioSystem);
    SAFE_DELETE(gp_DataFiles);

    return 0;
}