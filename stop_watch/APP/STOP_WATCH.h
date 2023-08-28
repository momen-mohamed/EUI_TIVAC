/* File: APP_StopWatch.h
 * Author: Momen Mohamed
 * Layer : Application
 * Description: Header file for the StopWatch application.
 */

#ifndef APP_STOP_WATCH_H_
#define APP_STOP_WATCH_H_

/* Enumeration: STOPWATCH_Status
 * Description: Status of the StopWatch (START or STOP).
 */

typedef enum
{
    START, STOP
} STOPWATCH_Status;

/* Enumeration: LAPS_type
 * Description: Types of laps (LAP1, LAP2, LAP3).
 */

typedef enum
{
    LAP1 = 0, LAP2, LAP3,
} LAPS_type;

/* Enumeration: WATCH_type
 * Description: Type of watch (COUNT or LAP).
 */

typedef enum
{
    COUNT, LAP
} WATCH_type;

/*************************FUNCTIONS PROTORTPES**************************/

/* Function: STOP_WATCH_Init
 * Description: Initializes the StopWatch.
 * Input: None
 * Output: None
 */
void STOP_WATCH_Init(void);

/* Function: STOP_WATCH_Runnable
 * Description: Main runnable function for the StopWatch application.
 * Input: None
 * Output: None
 */

void STOP_WATCH_Runnable(void);

/* Function: printStopWatchEntry
 * Description: Prints the StopWatch entry message.
 * Input: None
 * Output: None
 */
void printStopWatchEntery(void);

/* Function: resetWatch
 * Description: Resets the StopWatch.
 * Input: None
 * Output: None
 */
void resetWatch(void);

/* Function: printWatchAt
 * Description: Prints the watch count or lap at a specific line and cell.
 * Input: line - Line number (0 or 1)
 *        cell - Cell number (0 to 15)
 *        count - Watch count or lap value to print
 *        type - Type of watch (COUNT or LAP)
 * Output: None
 */
void printWatchAt(u8 line, u8 cell, u32 count, WATCH_type type);

#endif /* APP_STOP_WATCH_H_ */
