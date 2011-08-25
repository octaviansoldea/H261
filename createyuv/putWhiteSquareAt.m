function [bSuccess aimSquared] = putWhiteSquareAt(aarrTL, aarrSquareSizes, aIm)

    bSuccess = 1;
    [nImHeight nImWidth] = size(aIm);
    arrBR = aarrTL + aarrSquareSizes - 1;
    if((arrBR(1) > nImHeight) | (arrBR(2) > nImWidth))
        bSuccess = 0;
        aimSquared = [];
        disp('TAVI - Warning - problems in matrices dimensions');
        return;
    end;
    aimSquared = aIm;
    aimSquared(aarrTL(1) : arrBR(1), aarrTL(2) : arrBR(2), :) = 255;
    
end