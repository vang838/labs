#include "file.h"

/*******************************
 * Function: getPermissions
 * 
 * Description: Determines file type and permission string representation
 * 
 * @param mode File mode obtained from stat structure
 * @param perms Character array to store permissions string
 ******************************/
void getPermissions(mode_t mode, char *perms) 
{
   perms[0] = (S_ISDIR(mode)) ? 'd' :
              (S_ISLNK(mode)) ? 'l' :
              (S_ISCHR(mode)) ? 'c' :
              (S_ISBLK(mode)) ? 'b' :
              (S_ISFIFO(mode)) ? 'p' : '-';
            //   (S_ISSOCK(mode)) ? 's' : '-';

   perms[1] = (mode & S_IRUSR) ? 'r' : '-';
   perms[2] = (mode & S_IWUSR) ? 'w' : '-';
   perms[3] = (mode & S_IXUSR) ? 'x' : '-';
   perms[4] = (mode & S_IRGRP) ? 'r' : '-';
   perms[5] = (mode & S_IWGRP) ? 'w' : '-';
   perms[6] = (mode & S_IXGRP) ? 'x' : '-';
   perms[7] = (mode & S_IROTH) ? 'r' : '-';
   perms[8] = (mode & S_IWOTH) ? 'w' : '-';
   perms[9] = (mode & S_IXOTH) ? 'x' : '-';
   perms[10] = '\0';
}

/*******************************
 * Function: printFileDetails
 * 
 * Description: Prints detailed information about a file
 * 
 * @param path path to file
 * @param fileStat pointer to struct stat containing file info
 * @param fileName Name of the file
 ******************************/
void printFileDetails(char *path, struct stat *fileStat, char *fileName) 
{
   char permissions[11];
   getPermissions(fileStat->st_mode, permissions);

   struct passwd *passwd = getpwuid(fileStat->st_uid);
   struct group *gr = getgrgid(fileStat->st_gid);
   char time[20];
    
   strftime(time, sizeof(time), "%b %d %H:%M", localtime(&fileStat->st_mtime));

   printf("%s %ld %s %s %5ld %s %s\n", permissions, fileStat->st_nlink, passwd->pw_name, gr->gr_name, fileStat->st_size, time, fileName);
}

/*******************************
 * Function: listDirectory
 * 
 * Description: Displays files and directories in a specified directory if given, displays current directory if no input is given
 * 
 * @param dirPath path to directory
 * @param displayAll Flag that indicates to display hidden files and hidden directories
 * @param displayDetailed Flag that indicates to display detailed file info
 ******************************/
void listDirectory(char *dirPath, int displayAll, int displayDetailed) 
{
    DIR *dp;
    struct dirent *entry;

    dp = opendir(dirPath);
    if (dp == NULL) 
   {
      perror("opendir");
      return;
   }

   while ((entry = readdir(dp)) != NULL) 
   {
      if (!displayAll && entry->d_name[0] == '.') 
      {
         continue;
      }

      char fullPath[PATH_MAX];
      snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);
      struct stat fileStat;

      if (stat(fullPath, &fileStat) < 0) 
      {
         perror("Stat Error");
         continue;
      }

      if (displayDetailed) printFileDetails(fullPath, &fileStat, entry->d_name);
        
      else printf("%s  ", entry->d_name);
   }
   printf("\n");
   closedir(dp);
}

/*******************************
 * Function: lsExtended
 * 
 * Description: Parses command line arguments and executes similar ls unix command
 * 
 * @param argc Number of arguments
 * @param argv Array of argument strings
 * *****************************/
void lsExtended(int argc, char *argv[]) 
{  
   int showAll = 0;
   int detailed = 0;
   char *path = NULL;

   for (int i = 1; i < argc; i++) 
   {
      if (strcmp(argv[i], "-a") == 0) showAll = 1;

      else if (strcmp(argv[i], "-l") == 0) detailed = 1;

      else if (strcmp(argv[i], "-la") == 0 || strcmp(argv[i], "-al") == 0)
      {
         showAll = 1;
         detailed = 1;
      } 

      else path = argv[i];
    }

    if (path == NULL) 
    {
        path = getenv("PWD");
        if (path == NULL) 
        {
            printf("Error: Could not get the working directory\n");
            return;
        }
    }

    struct stat pathStat;
    if (stat(path, &pathStat) < 0) 
    {
        perror("Stat Error");
        return;
    }

    if (S_ISDIR(pathStat.st_mode)) listDirectory(path, showAll, detailed);
   
    else printFileDetails(path, &pathStat, path);
}
