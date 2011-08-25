function avi2YUV(adstYUVFileName, asrcAVIFileName) 
%reads asrcAVIFileName file in avi uncompressed format and writes it 
%as file adstYUVFileName in yuv format

    fid=fopen(adstYUVFileName,'wb');

    mov = aviread(asrcAVIFileName);
    nFramesNr = length(mov);
    for nI = 1 : nFramesNr
       
        im = mov(nI).cdata;
        imYUV = im2YUV_4Dump(im);
        fwrite(fid,imYUV,'uchar');
        
    end

    fclose(fid);

end