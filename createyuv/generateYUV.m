function bSuccess = generateYUV(anFramesNr, astrFormat, astrYUVFileName, aarrSquaresTL, aSize)
%self explaining.
%Input: anFramesNr - self explaining
%       astrFormat - can be 'CIF' or 'QCIF'
%       astrYUVFileName - self explaining
%       aarrSquaresTL - 2xanFramesNr array of bottom left corners 
%       aarrSquaresSizes - 2x2 matrix of size of the squares : all have the
%       same dimension
%Output: bSuccess - self explaining

    bSuccess = 1;
    
    if((nargin ~= 3) & (nargin ~= 5))
        disp('TAVI - Warning - problems in number of input arguments');
        bSuccess = 0;
        printUsage();
        return;
    end;

    if((strcmp(lower(astrFormat), 'qcif') == 0) & ((strcmp(lower(astrFormat), 'cif') == 0)))
        disp('TAVI - Warning - problems in qcif or cif specification');
        bSuccess = 0;
        printUsage();
        return;
    end;

    if(strcmp(lower(astrFormat), 'qcif') == 1)
        nHeight = 144;
        nWidth = 176;
    else
        nHeight = 288;
        nWidth = 352;
    end
    
    if((nargin == 5) & ((size(aarrSquaresTL, 1) ~= 2) | (size(aarrSquaresTL, 2) ~= anFramesNr) ))
        disp('TAVI - Warning - problems in top or left indices of squares specifications');
        bSuccess = 0;
        printUsage();
        return;
    end;

    if((nargin == 5) & (length(aSize) ~= 2))
        disp('TAVI - Warning - problems in the sizes of squares specifications');
        bSuccess = 0;
        printUsage();
        return;
    end;

    [fid, strMessage]=fopen(astrYUVFileName,'wb');
    if(fid == -1)
       
        bSuccess = 0;
        disp(strMessage);
        printUsage();
        return;
        
    end

    for nI = 1 : anFramesNr
    
        im = createBlackRGB(nHeight, nWidth);
        if(nargin == 5)
            arrTL = aarrSquaresTL(:, nI)'; 
            [bSuccess im] = putWhiteSquareAt(arrTL, aSize, im);
            if(bSuccess == 0)
                 fclose(fid);
                 disp('TAVI - Warning - problems at generation of squares');
                 return;
            end
        end
        imYUV = im2YUV_4Dump(im);
        fwrite(fid,imYUV,'uchar');
    end;

    fclose(fid);

end

function printUsage()

    disp('Usage:');
    disp('    bSuccess = generateYUV(anFramesNr, astrFormat, astrYUVFileName, aarrSquaresTL, aSize)');
    disp('or');
    disp('    bSuccess = generateYUV(anFramesNr, astrFormat, astrYUVFileName)');

end

