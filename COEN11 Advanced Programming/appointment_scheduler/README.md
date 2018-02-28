## appointment_scheduler
Uses a character array to allow names to be entered, deleted, and listed. 
Names can also be inserted at the beginning of the array, and the occurrences of a specific letter in the array can be counted.

After initialization, enter a number 1-5:

1 - Schedules a one-hour appointment at the next available time between 1pm and 6pm (does not allow duplicate names).

2 - Cancels an appointment and moves all later appointments up one hour to fill the empty time slot (scheduled order is maintained).

3 - Lists the scheduled appointments.

4 - Schedules an emergency appointment:
      Allows a name to be inserted at the beginning of the schedule (1pm)
      All other names will be shifted later one hour
      If the schedule is full, the last appointment will be removed, and the name of the cancelled appointment will be displayed
      
5 - Searches the array for a specific letter and displays the number of occurrences.

To quit, enter any other number or character.
