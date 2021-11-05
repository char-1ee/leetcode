-- Using CASE...WHEN
UPDATE Salary SET sex =
    CASE sex WHEN 'm' THEN 'f'
    WHEN 'f' THEN 'm' 
    end;

-- Using IF()
UPDATE Salary SET sex = if(sex ='m', 'f', 'm');

-- Using ASCII()
Update Salary set sex = (ASCII('m') + ASCII('f') - ASCII(sex));
Update Salary set sex = (ASCII('m') ^ ASCII('f') ^ ASCII(sex));