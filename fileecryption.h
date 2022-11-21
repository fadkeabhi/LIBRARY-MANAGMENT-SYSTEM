string LIB::encrypt(string text,string pass)
{
    int sizedata,sizepass,i,j,rem,div;
    sizedata = text.size();
    sizepass = pass.size();
    div = sizedata/sizepass;
    rem = sizedata%sizepass;

    //encrypting
    for(i=0;i<div;i++)
    {
        for(j=0;j<sizepass;j++)
        {
            if(j%2==0)
            {
                text[i*sizepass+j] += pass[j];
            }
            if(j%2==1)
            {
                text[i*sizepass+j] -= pass[j];
            }
        }
    }

    for(j=0;j<rem;j++)
    {
        if(j%2==0)
        {
            text[div*sizepass+j] += pass[j];
        }
        if(j%2==1)
        {
            text[div*sizepass+j] -= pass[j];
        }
    }
    return text;
}



string LIB::decrypt(string ret,string pass)
{
   
    //decrypting
    int sizedata = ret.size();
    int sizepass = pass.size();
    int i,j;
    int div=sizedata/sizepass;
    int rem=sizedata%sizepass;


    for(i=0;i<div;i++)
    {
        for(j=0;j<sizepass;j++)
        {
            if(j%2==0)
            {
                ret[i*sizepass+j] -= pass[j];
            }
            if(j%2==1)
            {
                ret[i*sizepass+j] += pass[j];
            }
        }
    }

    for(j=0;j<rem;j++)
    {
        if(j%2==0)
        {
            ret[div*sizepass+j] -= pass[j];
        }
        if(j%2==1)
        {
            ret[div*sizepass+j] += pass[j];
        }
    }
    return ret;
}