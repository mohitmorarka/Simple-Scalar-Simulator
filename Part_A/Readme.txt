
READ ME 


PART A 


Q1.(a)


Commands:



Major Code Modifications ( All edits are searchable via CS203A ):


2.  Stream Buffer Configuration string declaration

> static char *cache_sbd1_opt; ( Instruction )


> static char *cache_sbi1_opt; ( Data)


3. Stream Buffer Latency

>static int cache_sbi1_lat; (Instruction)


>static int cache_sbd1_lat; (Cache)


4. Stream Buffer Instance Created

>static struct cache_t *sbufferi1 (Instruction)


>static struct cache_t *sbufferd1 (Data)


5. Addition of this block to L1 mishandler function to allow stream buffer to be accessed incase of a cache miss

>if(sbufferd1)  ( For Data )

    {

    /* access Stream Buffer Data */

    fprintf(stderr, "L1 Data - Mishandler Access");

          return cache_access(sbufferd1, cmd, baddr, NULL, bsize,  /* now */now, /* pudata */NULL, /* repl addr */NULL); 

        

    }        


> if(sbufferi1)  ( Instruction)

    {    fprintf(stderr,"L1 INSTRUCTION -ACCESS");

    

          return cache_access(sbufferi1, cmd, baddr, NULL, bsize,  /* now */now, /* pudata */NULL, /* repl addr */NULL); 

            

    }       


6. Added a mishandler function for streambuffer where it accesses L2 cache.


7. Enable user input for stream buffer  via

>opt_reg_string(odb, "-cache:sbd1",                                 (Data)

         "Stream Buffer Data, i.e., {<config>|none}",

         &cache_sbd1_opt, "sbd1:1024:8:4:f",

         /* print */TRUE, NULL);


>opt_reg_string(odb, "-cache:sbi1",                                 (Instruction)

         "Stream Buffer Instruction, i.e., {<config>|none}",

         &cache_sbi1_opt, "sbi1:1024:8:4:f",

         /* print */TRUE, NULL);


8. Creation of Stream Buffer

>Data

if (!mystricmp(cache_sbd1_opt, "none"))

   

     sbufferd1 = NULL;

      else

    {

      if (sscanf(cache_sbd1_opt, "%[^:]:%d:%d:%d:%c",

             name, &nsets, &bsize, &assoc, &c) != 5)

             fatal("bad stream buffer data parameters: "

          "<name>:<nsets>:<bsize>:<assoc>:<repl>");

      sbufferd1 = cache_create(name, nsets, bsize, /* balloc */FALSE,

                   /* usize */0, assoc, cache_char2policy(c),

                   sbd1_access_fn, /* hit lat */cache_sbd1_lat);

   

    }


>Instruction

if (!mystricmp(cache_sbi1_opt, "none"))

   

     sbufferi1 = NULL;

      else

    {

      if (sscanf(cache_sbi1_opt, "%[^:]:%d:%d:%d:%c",

             name, &nsets, &bsize, &assoc, &c) != 5)

             fatal("bad stream buffer data parameters: "

          "<name>:<nsets>:<bsize>:<assoc>:<repl>");

      sbufferi1 = cache_create(name, nsets, bsize, /* balloc */FALSE,

                   /* usize */0, assoc, cache_char2policy(c),

                   sbi1_access_fn, /* hit lat */cache_sbi1_lat);

   

    }


9. Implemented Stream Buffer Flush using cache_flush

