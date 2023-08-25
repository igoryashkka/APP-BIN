#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h> 
#include "lib.h"

#define MAX_LOG_MESSAGE_LENGTH 1024

void secure_print(const char *format, ...) {
    // Initialize buffer to store the formatted log message
    char buffer[MAX_LOG_MESSAGE_LENGTH];
    
    // Validate format string
    if (strlen(format) >= MAX_LOG_MESSAGE_LENGTH) {
        fprintf(stderr, "Error: Log message too long\n");
        return;
    }
    
    va_list args;
    va_start(args, format);

    ///
    // Perform format string validation by parsing format string
    // ...
    ///
    
    // Format the log message securely
    int result = vsnprintf(buffer, sizeof(buffer), format, args);
    
    va_end(args);
    
    // Check for format string truncation
    if (result < 0 || result >= sizeof(buffer)) {
        fprintf(stderr, "Error: Log message truncated\n");
        return;
    }
    
    // Log the message to the console (replace with desired output location)
    printf("%s\n", buffer);
}

//TODO : 
// cli 
//error handling 
//secure
//refact make (dirs)
// perfomance
// conditional compile mode (run|debug)

void show_greetings(){
   secure_print("Hello user , it`s a binary application where you can perfome different manipulation with binary numbers");
   secure_print("For examples :");
   secure_print("[1] - Change any bit of you decimal number");
   secure_print("[2] - Conversation decimal to binary or vice versa");
   secure_print("[3] - Conversation float-pointing naumbers to binary");
   secure_print("[4] - Additional functionality\n");
}

void show_menu_changging_bits(){
   secure_print("You choose : [1] Changging bits");
   secure_print("You can perfome :");
   secure_print("[1] - reset_bit");
   secure_print("[2] - set_bit ");
   secure_print("[3] - toggle_bit ");
   secure_print("[4] - check_bit");
}

void cat(){  printf("         /\\_/\\              /\\_/\\  \n");
    printf("    ____/ o o \\            ( o.o )   - Hello, it's APP-BIN for converting binary numbers!\n");
    printf("  /~____  =ø= /              > ^ <  \n");
    printf(" (______)__m_m)\n");
    }


int main() {
  
   cat();
   show_greetings();
  

   
   int user_input = 0;
   scanf("%d", &user_input);

   system("clear");


   switch (user_input)
   {
   case 1:
   
      cat();
      show_menu_changging_bits();
      
      break;
   
   default:
      break;
   }

    

    

   

    return 0;
}
