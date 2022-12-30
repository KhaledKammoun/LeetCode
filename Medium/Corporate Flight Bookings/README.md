# Corp Flight Bookings
This code is a solution to the problem of calculating the number of passengers on a given flight at any given time.

## Contents

The corpFlightBookings method processes the bookings vector to create a temporary vector (t1) of length n+1 with initial values of zero.
It then iterates through the bookings vector and updates the values in t1 according to the start and end times and number of passengers specified in each booking.

Finally, the method iterates through t1 again, adding the value of each element to the value of the previous element to get a cumulative sum.
The method then returns a subvector of t1 containing the elements from the first element to the second to last element.

## Requirements

The code is written in C++ and has no external dependencies. It should be compatible with any C++ compiler.
