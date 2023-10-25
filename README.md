# Formatter

Purpose: 

The purpose of this program is to allow for the pulling of data from a specific website that does not have such a capability. 

A buffer prep laboratory may often have a request website that partnered biochem labs may request buffers from. My current lab has this, 
but that also comes with the responsibility of keeping track of which buffers have been made and by how much, which leads to another 
common feature of a manufacturing laboratory: monthly metrics. 

The current website that I utilize, is an outdated (and frankly broken) wesbite function which is supposed to return an organized list
of completed buffers and total amounts for and from any requested timeframe. Because this hasn't been updated, the user is required
to manually clean up and sum their data using excel. I want to avoid this, so I've created a program that does this for me. 

Methods: 

1) The program will prompt you to give a file name (CSV pulled from the website) and a month that you would like to retrieve data for.
2) The program will create a vector from this parsed CSV while resizing it by deleting out-of-range buffers.
3) If the buffer is not in the list, it will be assumed to be an unnamed "special request".
4) It will then perform summations of all buffers, both in request and volume size.
5) this will all be performed in the scope of the original CSV.

Conclusion: 
Given  the basic goal of this program, perhaps it can eventually be added to the website's functionality. Though the manual cleaning of 
data is not a complex task, this may: take useful time out of a worker's day, be suscpetible to small mistakes, and require additional training
of new hires. I wish that this program may encourage further updates from this website. 


