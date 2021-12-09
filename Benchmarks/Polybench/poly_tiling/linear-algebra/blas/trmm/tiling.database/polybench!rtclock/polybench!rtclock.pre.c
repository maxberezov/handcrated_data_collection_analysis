static double rtclock()
{

   struct timeval Tp;
   int stat;
   stat = gettimeofday(&Tp, (void *) 0);
   if (stat!=0)
      printf("Error return from gettimeofday: %d", stat);
   return Tp.tv_sec+Tp.tv_usec*1.0e-6;
}
