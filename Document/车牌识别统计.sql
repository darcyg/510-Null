use zslh
go

declare @dt as datetime
declare @dt1 as datetime
set @dt='2013-6-5 16:50'
set @dt1=getdate()
select a.EntranceName, b.Count as  [ʶ����],a.Count as [����],cast(cast(b.count as decimal(10,2))/a.count as decimal(10,3))as [ʶ����]
from 
(select EntranceID,EntranceName,count(*) as count from cardevent 
where EventDateTime>@dt and eventdatetime<@dt1 
and exists (select * from snapshot where cardevent.eventdatetime=snapshot.shotat) 
group by EntranceID,EntranceName ) a
left join
(select EntranceID,EntranceName,count(*) as count from cardevent 
where EventDateTime>@dt and eventdatetime<@dt1 and carPlate <>''
--and carplate not like '%��%' and carplate not like '%?%' and carplate not like '%��%'
and exists (select * from snapshot where cardevent.eventdatetime=snapshot.shotat) 
group by EntranceID,EntranceName ) b
on a.EntranceID=b.EntranceID
order by a.entrancename

