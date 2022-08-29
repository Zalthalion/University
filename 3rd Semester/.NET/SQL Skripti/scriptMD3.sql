/*    ==Scripting Parameters==

    Source Server Version : SQL Server 2016 (13.0.4259)
    Source Database Engine Edition : Microsoft SQL Server Express Edition
    Source Database Engine Type : Standalone SQL Server

    Target Server Version : SQL Server 2017
    Target Database Engine Edition : Microsoft SQL Server Standard Edition
    Target Database Engine Type : Standalone SQL Server
*/
ALTER TABLE [person_author] DROP CONSTRAINT [CK__authors__zip__25869641]
GO
ALTER TABLE [jobs] DROP CONSTRAINT [CK__jobs__min_lvl__3F466844]
GO
ALTER TABLE [jobs] DROP CONSTRAINT [CK__jobs__max_lvl__403A8C7D]
GO
ALTER TABLE [titles] DROP CONSTRAINT [FK_titles_publishers]
GO
ALTER TABLE [titleauthor] DROP CONSTRAINT [FK_titleauthor_titles]
GO
ALTER TABLE [titleauthor] DROP CONSTRAINT [FK_titleauthor_authors]
GO
ALTER TABLE [sales] DROP CONSTRAINT [FK_sales_titles]
GO
ALTER TABLE [sales] DROP CONSTRAINT [FK_sales_stores]
GO
ALTER TABLE [pub_info] DROP CONSTRAINT [FK_pub_info_publishers]
GO
ALTER TABLE [person_employee] DROP CONSTRAINT [FK_employee_publishers]
GO
ALTER TABLE [person_employee] DROP CONSTRAINT [FK_employee_person]
GO
ALTER TABLE [person_employee] DROP CONSTRAINT [FK__employee__job_id__47DBAE45]
GO
ALTER TABLE [person_author] DROP CONSTRAINT [FK_authors_person]
GO
ALTER TABLE [titles] DROP CONSTRAINT [DF__titles__pubdate__2E1BDC42]
GO
ALTER TABLE [titles] DROP CONSTRAINT [DF__titles__type__2C3393D0]
GO
ALTER TABLE [publishers] DROP CONSTRAINT [DF__publisher__count__29572725]
GO
ALTER TABLE [person_employee] DROP CONSTRAINT [DF__employee__hire_d__4BAC3F29]
GO
ALTER TABLE [person_employee] DROP CONSTRAINT [DF__employee__job_lv__48CFD27E]
GO
ALTER TABLE [person_employee] DROP CONSTRAINT [DF__employee__job_id__46E78A0C]
GO
ALTER TABLE [person_author] DROP CONSTRAINT [DF__authors__phone__24927208]
GO
ALTER TABLE [jobs] DROP CONSTRAINT [DF__jobs__job_desc__3E52440B]
GO
DROP TABLE [titles]
GO
DROP TABLE [titleauthor]
GO
DROP TABLE [stores]
GO
DROP TABLE [sales]
GO
DROP TABLE [publishers]
GO
DROP TABLE [pub_info]
GO
DROP TABLE [person_employee]
GO
DROP TABLE [person_author]
GO
DROP TABLE [person]
GO
DROP TABLE [jobs]
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [jobs](
	[job_id] [smallint] IDENTITY(1,1) NOT NULL,
	[job_desc] [varchar](50) NOT NULL,
	[min_lvl] [tinyint] NOT NULL,
	[max_lvl] [tinyint] NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[job_id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
ALTER AUTHORIZATION ON [jobs] TO  SCHEMA OWNER 
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [person](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[fname] [varchar](20) NULL,
	[lname] [varchar](40) NULL,
 CONSTRAINT [PK_Person] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
ALTER AUTHORIZATION ON [person] TO  SCHEMA OWNER 
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [person_author](
	[phone] [char](12) NOT NULL,
	[address] [varchar](40) NULL,
	[city] [varchar](20) NULL,
	[state] [char](2) NULL,
	[zip] [char](5) NULL,
	[contract] [bit] NOT NULL,
	[ID] [int] NOT NULL,
 CONSTRAINT [PK_authors] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
ALTER AUTHORIZATION ON [person_author] TO  SCHEMA OWNER 
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [person_employee](
	[minit] [char](1) NULL,
	[job_id] [smallint] NOT NULL,
	[job_lvl] [tinyint] NULL,
	[hire_date] [datetime] NOT NULL,
	[pubID] [int] NULL,
	[ID] [int] NOT NULL,
 CONSTRAINT [PK_employee] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
ALTER AUTHORIZATION ON [person_employee] TO  SCHEMA OWNER 
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [pub_info](
	[logo] [image] NULL,
	[pr_info] [text] NULL,
	[pubID] [int] NOT NULL,
 CONSTRAINT [PK_pub_info] PRIMARY KEY CLUSTERED 
(
	[pubID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
ALTER AUTHORIZATION ON [pub_info] TO  SCHEMA OWNER 
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [publishers](
	[pub_name] [varchar](40) NULL,
	[city] [varchar](20) NULL,
	[state] [char](2) NULL,
	[country] [varchar](30) NULL,
	[ID] [int] IDENTITY(1,1) NOT NULL,
 CONSTRAINT [PK_publishers] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
ALTER AUTHORIZATION ON [publishers] TO  SCHEMA OWNER 
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [sales](
	[ord_num] [varchar](20) NOT NULL,
	[ord_date] [datetime] NOT NULL,
	[qty] [smallint] NOT NULL,
	[payterms] [varchar](12) NOT NULL,
	[titleID] [int] NULL,
	[storID] [int] NULL,
	[ID] [int] IDENTITY(1,1) NOT NULL,
 CONSTRAINT [PK_sales] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
ALTER AUTHORIZATION ON [sales] TO  SCHEMA OWNER 
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [stores](
	[stor_name] [varchar](40) NULL,
	[stor_address] [varchar](40) NULL,
	[city] [varchar](20) NULL,
	[state] [char](2) NULL,
	[zip] [char](5) NULL,
	[ID] [int] IDENTITY(1,1) NOT NULL,
 CONSTRAINT [PK_stores] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
ALTER AUTHORIZATION ON [stores] TO  SCHEMA OWNER 
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [titleauthor](
	[au_ord] [tinyint] NULL,
	[royaltyper] [int] NULL,
	[titleID] [int] NULL,
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[personId] [int] NULL,
 CONSTRAINT [PK_titleauthor] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
ALTER AUTHORIZATION ON [titleauthor] TO  SCHEMA OWNER 
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [titles](
	[title] [varchar](80) NOT NULL,
	[titleType] [char](12) NOT NULL,
	[price] [money] NULL,
	[advance] [money] NULL,
	[royalty] [int] NULL,
	[ytd_sales] [int] NULL,
	[notes] [varchar](200) NULL,
	[pubdate] [datetime] NOT NULL,
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[pubID] [int] NULL,
 CONSTRAINT [PK_titles] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
ALTER AUTHORIZATION ON [titles] TO  SCHEMA OWNER 
GO
SET IDENTITY_INSERT [jobs] ON 

INSERT [jobs] ([job_id], [job_desc], [min_lvl], [max_lvl]) VALUES (1, N'New Hire - Job not specified', 10, 10)
INSERT [jobs] ([job_id], [job_desc], [min_lvl], [max_lvl]) VALUES (2, N'Chief Executive Officer', 200, 250)
INSERT [jobs] ([job_id], [job_desc], [min_lvl], [max_lvl]) VALUES (3, N'Business Operations Manager', 175, 225)
INSERT [jobs] ([job_id], [job_desc], [min_lvl], [max_lvl]) VALUES (4, N'Chief Financial Officier', 175, 250)
INSERT [jobs] ([job_id], [job_desc], [min_lvl], [max_lvl]) VALUES (5, N'Publisher', 150, 250)
INSERT [jobs] ([job_id], [job_desc], [min_lvl], [max_lvl]) VALUES (6, N'Managing Editor', 140, 225)
INSERT [jobs] ([job_id], [job_desc], [min_lvl], [max_lvl]) VALUES (7, N'Marketing Manager', 120, 200)
INSERT [jobs] ([job_id], [job_desc], [min_lvl], [max_lvl]) VALUES (8, N'Public Relations Manager', 100, 175)
INSERT [jobs] ([job_id], [job_desc], [min_lvl], [max_lvl]) VALUES (9, N'Acquisitions Manager', 75, 175)
INSERT [jobs] ([job_id], [job_desc], [min_lvl], [max_lvl]) VALUES (10, N'Productions Manager', 75, 165)
INSERT [jobs] ([job_id], [job_desc], [min_lvl], [max_lvl]) VALUES (11, N'Operations Manager', 75, 150)
INSERT [jobs] ([job_id], [job_desc], [min_lvl], [max_lvl]) VALUES (12, N'Editor', 25, 100)
INSERT [jobs] ([job_id], [job_desc], [min_lvl], [max_lvl]) VALUES (13, N'Sales Representative', 25, 100)
INSERT [jobs] ([job_id], [job_desc], [min_lvl], [max_lvl]) VALUES (14, N'Designer', 25, 100)
SET IDENTITY_INSERT [jobs] OFF
SET IDENTITY_INSERT [person] ON 

INSERT [person] ([ID], [fname], [lname]) VALUES (67, N'Aria', N'Cruz')
INSERT [person] ([ID], [fname], [lname]) VALUES (68, N'Ann', N'Devon')
INSERT [person] ([ID], [fname], [lname]) VALUES (69, N'Annette', N'Roulet')
INSERT [person] ([ID], [fname], [lname]) VALUES (70, N'Anabela', N'Domingues')
INSERT [person] ([ID], [fname], [lname]) VALUES (71, N'Carlos', N'Hernadez')
INSERT [person] ([ID], [fname], [lname]) VALUES (72, N'Carine', N'Schmitt')
INSERT [person] ([ID], [fname], [lname]) VALUES (73, N'Daniel', N'Tonini')
INSERT [person] ([ID], [fname], [lname]) VALUES (74, N'Diego', N'Roel')
INSERT [person] ([ID], [fname], [lname]) VALUES (75, N'Elizabeth', N'Lincoln')
INSERT [person] ([ID], [fname], [lname]) VALUES (76, N'Francisco', N'Chang')
INSERT [person] ([ID], [fname], [lname]) VALUES (77, N'Gary', N'Thomas')
INSERT [person] ([ID], [fname], [lname]) VALUES (78, N'Helvetius', N'Nagy')
INSERT [person] ([ID], [fname], [lname]) VALUES (79, N'Howard', N'Snyder')
INSERT [person] ([ID], [fname], [lname]) VALUES (80, N'Helen', N'Bennett')
INSERT [person] ([ID], [fname], [lname]) VALUES (81, N'Janine', N'Labrune')
INSERT [person] ([ID], [fname], [lname]) VALUES (82, N'Karin', N'Josephs')
INSERT [person] ([ID], [fname], [lname]) VALUES (83, N'Karla', N'Jablonski')
INSERT [person] ([ID], [fname], [lname]) VALUES (84, N'Laurence', N'Lebihan')
INSERT [person] ([ID], [fname], [lname]) VALUES (85, N'Lesley', N'Brown')
INSERT [person] ([ID], [fname], [lname]) VALUES (86, N'Miguel', N'Paolino')
INSERT [person] ([ID], [fname], [lname]) VALUES (87, N'Margaret', N'Smith')
INSERT [person] ([ID], [fname], [lname]) VALUES (88, N'Martin', N'Sommer')
INSERT [person] ([ID], [fname], [lname]) VALUES (89, N'Matti', N'Karttunen')
INSERT [person] ([ID], [fname], [lname]) VALUES (90, N'Maria', N'Pontes')
INSERT [person] ([ID], [fname], [lname]) VALUES (91, N'Maria', N'Larsson')
INSERT [person] ([ID], [fname], [lname]) VALUES (92, N'Mary', N'Saveley')
INSERT [person] ([ID], [fname], [lname]) VALUES (93, N'Manuel', N'Pereira')
INSERT [person] ([ID], [fname], [lname]) VALUES (94, N'Martine', N'Rance')
INSERT [person] ([ID], [fname], [lname]) VALUES (95, N'Patricia', N'McKenna')
INSERT [person] ([ID], [fname], [lname]) VALUES (96, N'Palle', N'Ibsen')
INSERT [person] ([ID], [fname], [lname]) VALUES (97, N'Peter', N'Franken')
INSERT [person] ([ID], [fname], [lname]) VALUES (98, N'Paolo', N'Accorti')
INSERT [person] ([ID], [fname], [lname]) VALUES (99, N'Pirkko', N'Koskitalo')
INSERT [person] ([ID], [fname], [lname]) VALUES (100, N'Pedro', N'Afonso')
INSERT [person] ([ID], [fname], [lname]) VALUES (101, N'Paula', N'Parente')
INSERT [person] ([ID], [fname], [lname]) VALUES (102, N'Philip', N'Cramer')
INSERT [person] ([ID], [fname], [lname]) VALUES (103, N'Paul', N'Henriot')
INSERT [person] ([ID], [fname], [lname]) VALUES (104, N'Rita', N'Muller')
INSERT [person] ([ID], [fname], [lname]) VALUES (105, N'Roland', N'Mendel')
INSERT [person] ([ID], [fname], [lname]) VALUES (106, N'Sven', N'Ottlieb')
INSERT [person] ([ID], [fname], [lname]) VALUES (107, N'Timothy', N'O''Rourke')
INSERT [person] ([ID], [fname], [lname]) VALUES (108, N'Victoria', N'Ashworth')
INSERT [person] ([ID], [fname], [lname]) VALUES (109, N'Yoshi', N'Latimer')
INSERT [person] ([ID], [fname], [lname]) VALUES (110, N'Abraham', N'Bennet')
INSERT [person] ([ID], [fname], [lname]) VALUES (111, N'Reginald', N'Blotchet-Halls')
INSERT [person] ([ID], [fname], [lname]) VALUES (112, N'Cheryl', N'Carson')
INSERT [person] ([ID], [fname], [lname]) VALUES (113, N'Michel', N'DeFrance')
INSERT [person] ([ID], [fname], [lname]) VALUES (114, N'Innes', N'del Castillo')
INSERT [person] ([ID], [fname], [lname]) VALUES (115, N'Ann', N'Dull')
INSERT [person] ([ID], [fname], [lname]) VALUES (116, N'Marjorie', N'Green')
INSERT [person] ([ID], [fname], [lname]) VALUES (117, N'Morningstar', N'Greene')
INSERT [person] ([ID], [fname], [lname]) VALUES (118, N'Burt', N'Gringlesby')
INSERT [person] ([ID], [fname], [lname]) VALUES (119, N'Sheryl', N'Hunter')
INSERT [person] ([ID], [fname], [lname]) VALUES (120, N'Livia', N'Karsen')
INSERT [person] ([ID], [fname], [lname]) VALUES (121, N'Charlene', N'Locksley')
INSERT [person] ([ID], [fname], [lname]) VALUES (122, N'Stearns', N'MacFeather')
INSERT [person] ([ID], [fname], [lname]) VALUES (123, N'Heather', N'McBadden')
INSERT [person] ([ID], [fname], [lname]) VALUES (124, N'Michael', N'O''Leary')
INSERT [person] ([ID], [fname], [lname]) VALUES (125, N'Sylvia', N'Panteley')
INSERT [person] ([ID], [fname], [lname]) VALUES (126, N'Albert', N'Ringer')
INSERT [person] ([ID], [fname], [lname]) VALUES (127, N'Anne', N'Ringer')
INSERT [person] ([ID], [fname], [lname]) VALUES (128, N'Meander', N'Smith')
INSERT [person] ([ID], [fname], [lname]) VALUES (129, N'Dean', N'Straight')
INSERT [person] ([ID], [fname], [lname]) VALUES (130, N'Dirk', N'Stringer')
INSERT [person] ([ID], [fname], [lname]) VALUES (131, N'Johnson', N'White')
INSERT [person] ([ID], [fname], [lname]) VALUES (132, N'Akiko', N'Yokomoto')
SET IDENTITY_INSERT [person] OFF
INSERT [person_author] ([phone], [address], [city], [state], [zip], [contract], [ID]) VALUES (N'415 658-9932', N'6223 Bateman St.', N'Berkeley', N'CA', N'94705', 1, 110)
INSERT [person_author] ([phone], [address], [city], [state], [zip], [contract], [ID]) VALUES (N'503 745-6402', N'55 Hillsdale Bl.', N'Corvallis', N'OR', N'97330', 1, 111)
INSERT [person_author] ([phone], [address], [city], [state], [zip], [contract], [ID]) VALUES (N'415 548-7723', N'589 Darwin Ln.', N'Berkeley', N'CA', N'94705', 1, 112)
INSERT [person_author] ([phone], [address], [city], [state], [zip], [contract], [ID]) VALUES (N'219 547-9982', N'3 Balding Pl.', N'Gary', N'IN', N'46403', 1, 113)
INSERT [person_author] ([phone], [address], [city], [state], [zip], [contract], [ID]) VALUES (N'615 996-8275', N'2286 Cram Pl. #86', N'Ann Arbor', N'MI', N'48105', 1, 114)
INSERT [person_author] ([phone], [address], [city], [state], [zip], [contract], [ID]) VALUES (N'415 836-7128', N'3410 Blonde St.', N'Palo Alto', N'CA', N'94301', 1, 115)
INSERT [person_author] ([phone], [address], [city], [state], [zip], [contract], [ID]) VALUES (N'415 986-7020', N'309 63rd St. #411', N'Oakland', N'CA', N'94618', 1, 116)
INSERT [person_author] ([phone], [address], [city], [state], [zip], [contract], [ID]) VALUES (N'615 297-2723', N'22 Graybar House Rd.', N'Nashville', N'TN', N'37215', 0, 117)
INSERT [person_author] ([phone], [address], [city], [state], [zip], [contract], [ID]) VALUES (N'707 938-6445', N'PO Box 792', N'Covelo', N'CA', N'95428', 1, 118)
INSERT [person_author] ([phone], [address], [city], [state], [zip], [contract], [ID]) VALUES (N'415 836-7128', N'3410 Blonde St.', N'Palo Alto', N'CA', N'94301', 1, 119)
INSERT [person_author] ([phone], [address], [city], [state], [zip], [contract], [ID]) VALUES (N'415 534-9219', N'5720 McAuley St.', N'Oakland', N'CA', N'94609', 1, 120)
INSERT [person_author] ([phone], [address], [city], [state], [zip], [contract], [ID]) VALUES (N'415 585-4620', N'18 Broadway Av.', N'San Francisco', N'CA', N'94130', 1, 121)
INSERT [person_author] ([phone], [address], [city], [state], [zip], [contract], [ID]) VALUES (N'415 354-7128', N'44 Upland Hts.', N'Oakland', N'CA', N'94612', 1, 122)
INSERT [person_author] ([phone], [address], [city], [state], [zip], [contract], [ID]) VALUES (N'707 448-4982', N'301 Putnam', N'Vacaville', N'CA', N'95688', 0, 123)
INSERT [person_author] ([phone], [address], [city], [state], [zip], [contract], [ID]) VALUES (N'408 286-2428', N'22 Cleveland Av. #14', N'San Jose', N'CA', N'95128', 1, 124)
INSERT [person_author] ([phone], [address], [city], [state], [zip], [contract], [ID]) VALUES (N'301 946-8853', N'1956 Arlington Pl.', N'Rockville', N'MD', N'20853', 1, 125)
INSERT [person_author] ([phone], [address], [city], [state], [zip], [contract], [ID]) VALUES (N'801 826-0752', N'67 Seventh Av.', N'Salt Lake City', N'UT', N'84152', 1, 126)
INSERT [person_author] ([phone], [address], [city], [state], [zip], [contract], [ID]) VALUES (N'801 826-0752', N'67 Seventh Av.', N'Salt Lake City', N'UT', N'84152', 1, 127)
INSERT [person_author] ([phone], [address], [city], [state], [zip], [contract], [ID]) VALUES (N'913 843-0462', N'10 Mississippi Dr.', N'Lawrence', N'KS', N'66044', 0, 128)
INSERT [person_author] ([phone], [address], [city], [state], [zip], [contract], [ID]) VALUES (N'415 834-2919', N'5420 College Av.', N'Oakland', N'CA', N'94609', 1, 129)
INSERT [person_author] ([phone], [address], [city], [state], [zip], [contract], [ID]) VALUES (N'415 843-2991', N'5420 Telegraph Av.', N'Oakland', N'CA', N'94609', 0, 130)
INSERT [person_author] ([phone], [address], [city], [state], [zip], [contract], [ID]) VALUES (N'408 496-7223', N'10932 Bigge Rd.', N'Menlo Park', N'CA', N'94025', 1, 131)
INSERT [person_author] ([phone], [address], [city], [state], [zip], [contract], [ID]) VALUES (N'415 935-4228', N'3 Silver Ct.', N'Walnut Creek', N'CA', N'94595', 1, 132)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N' ', 10, 87, CAST(N'1991-10-26T00:00:00.000' AS DateTime), 3, 67)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'M', 3, 200, CAST(N'1991-07-16T00:00:00.000' AS DateTime), 7, 68)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N' ', 6, 152, CAST(N'1990-02-21T00:00:00.000' AS DateTime), 8, 69)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'R', 8, 100, CAST(N'1993-01-27T00:00:00.000' AS DateTime), 2, 70)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'F', 5, 211, CAST(N'1989-04-21T00:00:00.000' AS DateTime), 8, 71)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'G', 13, 64, CAST(N'1992-07-07T00:00:00.000' AS DateTime), 3, 72)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'B', 11, 75, CAST(N'1990-01-01T00:00:00.000' AS DateTime), 2, 73)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'W', 6, 192, CAST(N'1991-12-16T00:00:00.000' AS DateTime), 3, 74)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'N', 14, 35, CAST(N'1990-07-24T00:00:00.000' AS DateTime), 2, 75)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N' ', 4, 227, CAST(N'1990-11-03T00:00:00.000' AS DateTime), 7, 76)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'H', 9, 170, CAST(N'1988-08-09T00:00:00.000' AS DateTime), 1, 77)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'A', 7, 120, CAST(N'1993-03-19T00:00:00.000' AS DateTime), 8, 78)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'A', 12, 100, CAST(N'1988-11-19T00:00:00.000' AS DateTime), 1, 79)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N' ', 12, 35, CAST(N'1989-09-21T00:00:00.000' AS DateTime), 2, 80)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'Y', 5, 172, CAST(N'1991-05-26T00:00:00.000' AS DateTime), 6, 81)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'F', 14, 100, CAST(N'1992-10-17T00:00:00.000' AS DateTime), 1, 82)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'J', 9, 170, CAST(N'1994-03-11T00:00:00.000' AS DateTime), 8, 83)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'A', 5, 175, CAST(N'1990-06-03T00:00:00.000' AS DateTime), 1, 84)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N' ', 7, 120, CAST(N'1991-02-13T00:00:00.000' AS DateTime), 2, 85)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'A', 11, 112, CAST(N'1992-12-07T00:00:00.000' AS DateTime), 3, 86)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'A', 9, 78, CAST(N'1988-09-29T00:00:00.000' AS DateTime), 3, 87)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'F', 10, 165, CAST(N'1990-04-13T00:00:00.000' AS DateTime), 1, 88)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'G', 6, 220, CAST(N'1994-05-01T00:00:00.000' AS DateTime), 1, 89)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'J', 5, 246, CAST(N'1989-03-01T00:00:00.000' AS DateTime), 5, 90)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N' ', 7, 135, CAST(N'1992-03-27T00:00:00.000' AS DateTime), 3, 91)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'M', 8, 175, CAST(N'1993-06-29T00:00:00.000' AS DateTime), 1, 92)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N' ', 8, 101, CAST(N'1989-01-09T00:00:00.000' AS DateTime), 8, 93)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N' ', 9, 75, CAST(N'1992-02-05T00:00:00.000' AS DateTime), 2, 94)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'C', 11, 150, CAST(N'1989-08-01T00:00:00.000' AS DateTime), 8, 95)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'D', 7, 195, CAST(N'1993-05-09T00:00:00.000' AS DateTime), 1, 96)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'H', 10, 75, CAST(N'1992-05-17T00:00:00.000' AS DateTime), 2, 97)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'M', 13, 35, CAST(N'1992-08-27T00:00:00.000' AS DateTime), 2, 98)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'O', 10, 80, CAST(N'1993-11-29T00:00:00.000' AS DateTime), 8, 99)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'S', 14, 89, CAST(N'1990-12-24T00:00:00.000' AS DateTime), 3, 100)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'S', 8, 125, CAST(N'1994-01-19T00:00:00.000' AS DateTime), 3, 101)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'T', 2, 215, CAST(N'1989-11-11T00:00:00.000' AS DateTime), 7, 102)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'X', 5, 159, CAST(N'1993-08-19T00:00:00.000' AS DateTime), 2, 103)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'B', 5, 198, CAST(N'1993-10-09T00:00:00.000' AS DateTime), 4, 104)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N' ', 11, 150, CAST(N'1991-09-05T00:00:00.000' AS DateTime), 1, 105)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'K', 5, 150, CAST(N'1991-04-05T00:00:00.000' AS DateTime), 3, 106)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'P', 13, 100, CAST(N'1988-06-19T00:00:00.000' AS DateTime), 1, 107)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N'P', 6, 140, CAST(N'1990-09-13T00:00:00.000' AS DateTime), 2, 108)
INSERT [person_employee] ([minit], [job_id], [job_lvl], [hire_date], [pubID], [ID]) VALUES (N' ', 12, 32, CAST(N'1989-06-11T00:00:00.000' AS DateTime), 3, 109)
INSERT [pub_info] ([logo], [pr_info], [pubID]) VALUES (0x474946383961D3001F00B30F00000000800000008000808000000080800080008080808080C0C0C0FF000000FF00FFFF000000FFFF00FF00FFFFFFFFFF21F9040100000F002C00000000D3001F004004FFF0C949ABBD38EBCDBBFF60288E245001686792236ABAB03BC5B055B3F843D3B99DE2AB532A36FB15253B19E5A6231A934CA18CB75C1191D69BF62AAD467F5CF036D8243791369F516ADEF9304AF8F30A3563D7E54CFC04BF24377B5D697E6451333D8821757F898D8E8F1F76657877907259755E5493962081798D9F8A846D9B4A929385A7A5458CA0777362ACAF585E6C6A84AD429555BAA9A471A89D8E8BA2C3C7C82DC9C8AECBCECF1EC2D09143A66E80D3D9BC2C41D76AD28FB2CD509ADAA9AAC62594A3DF81C65FE0BDB5B0CDF4E276DEF6DD78EF6B86FA6C82C5A2648A54AB6AAAE4C1027864DE392E3AF4582BF582DFC07D9244ADA2480BD4C6767BFF32AE0BF3EF603B3907490A4427CE21A7330A6D0584B810664D7F383FA25932488FB96D0F37BDF9491448D1A348937A52CAB4A9D3784EF5E58B4A5545D54BC568FABC9A68DD526ED0A6B8AA17331BD91E5AD9D1D390CED23D88F54A3ACB0A955ADDAD9A50B50D87296E3EB9C76A7CDAABC86B2460040DF34D3995515AB9FF125F1AFA0DAB20A0972382CCB9F9E5AEBC368B21EEDB66EDA15F1347BE2DFDEBB44A7B7C6889240D9473EB73322F4E8D8DBBE14D960B6519BCE5724BB95789350E97EA4BF3718CDD64068D751A261D8B1539D6DCDE3C37F68E1FB58E5DCED8A44477537049852EFD253CEE38C973B7E9D97A488C2979FB936FBAFF2CF5CB79E35830400C31860F4A9BE925D4439F81B6A073BEF1575F593C01A25B26127255D45D4A45B65B851A36C56154678568A20E1100003B, N'This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.
This is sample text data for New Moon Books, publisher 0736 in the pubs database. New Moon Books is located in Boston, Massachusetts.', 1)
INSERT [pub_info] ([logo], [pr_info], [pubID]) VALUES (0x4749463839618B002F00B30F00000000800000008000808000000080800080008080808080C0C0C0FF000000FF00FFFF000000FFFF00FF00FFFFFFFFFF21F9040100000F002C000000008B002F004004FFF0C949ABBD38EBCDBBFFA0048464089CE384A62BD596309CC6F4F58A287EBA79ED73B3D26A482C1A8FC8A47249FCCD76BC1F3058D94135579C9345053D835768560CFE6A555D343A1B6D3FC6DC2A377E66DBA5F8DBEBF6EEE1FF2A805B463A47828269871F7A3D7C7C8A3E899093947F666A756567996E6C519E167692646E7D9C98A42295ABAC24A092AD364C737EB15EB61B8E8DB58FB81DB0BE8C6470A0BE58C618BAC365C5C836CEA1BCBBC4C0D0AAD6D14C85CDD86FDDDFAB5F43A580DCB519A25B9BAE989BC3EEA9A7EBD9BF54619A7DF8BBA87475EDA770D6C58B968C59A27402FB99E2378FC7187010D5558948B15CC58B4E20CE9A762E62B558CAB86839FC088D24AB90854662BCD60D653E832BBD7924F49226469327FDEC91C6AD2538972E6FFEE429720D4E63472901251A33A9D28DB47A5A731A7325D56D50B36ADDAA2463D5AF1EAE82F5F84FAA946656AA21AC31D0C4BF85CBA87912D6D194D4B535C5DDDBA93221CB226D022E9437D89C594305FD321C0CB7DFA5C58223036E088F3139B9032563DD0BE66D2ACD8B2BCB9283CEDEE3C6A53EE39BA7579A62C1294917DC473035E0B9E3183F9A3BB6F7ABDE608B018800003B, N'This is sample text data for Binnet & Hardley, publisher 0877 in the pubs database. Binnet & Hardley is located in Washington, D.C.
This is sample text data for Binnet & Hardley, publisher 0877 in the pubs database. Binnet & Hardley is located in Washington, D.C.
This is sample text data for Binnet & Hardley, publisher 0877 in the pubs database. Binnet & Hardley is located in Washington, D.C.
This is sample text data for Binnet & Hardley, publisher 0877 in the pubs database. Binnet & Hardley is located in Washington, D.C.
This is sample text data for Binnet & Hardley, publisher 0877 in the pubs database. Binnet & Hardley is located in Washington, D.C.', 2)
INSERT [pub_info] ([logo], [pr_info], [pubID]) VALUES (0x474946383961C2001D00B30F00000000800000008000808000000080800080008080808080C0C0C0FF000000FF00FFFF000000FFFF00FF00FFFFFFFFFF21F9040100000F002C00000000C2001D004004FFF0C949ABBD38EBCDBBFF60288E1C609E2840AE2C969E6D2CCFB339D90F2CE1F8AEE6BC9FEF26EC01413AA3F2D76BAA96C7A154EA7CC29C449AC7A8ED7A2FDC2FED25149B29E4D479FD55A7CBD931DC35CFA4916171BEFDAABC51546541684C8285847151537F898A588D89806045947491757B6C9A9B9C9D9E9FA0A1A2A3A4A5A6A7A8A95A6A3E64169923B0901A775B7566B25D7F8C888A5150BE7B8F93847D8DC3C07983BEBDC1878BCFAF6F44BBD0AD71C9CBD653BFD5CEC7D1C3DFDB8197D8959CB9AAB8B7EBEEEFF0BA92F1B6B5F4A0F6F776D3FA9EBCFD748C01DCB4AB5DBF7C03CF1454070F61423D491C326BA18E211081250C7AB12867619825F37F2ECE1168AC242B6A274556D121D28FA46C11E78564C5B295308F21BBF5CAD6CCE52C7018813932C4ED5C517346B7C1C2683368349D49A19D0439D31538A452A916135A0B19A59AAB9E6A835A0EABD00E5CD11D1D478C1C59714053AA4C4955AB4B9956879AB497F62E1CBA2373DA25B752239F8787119390AB5806C74E1100003B, N'This is sample text data for Algodata Infosystems, publisher 1389 in the pubs database. Algodata Infosystems is located in Berkeley, California.
This is sample text data for Algodata Infosystems, publisher 1389 in the pubs database. Algodata Infosystems is located in Berkeley, California.
This is sample text data for Algodata Infosystems, publisher 1389 in the pubs database. Algodata Infosystems is located in Berkeley, California.
This is sample text data for Algodata Infosystems, publisher 1389 in the pubs database. Algodata Infosystems is located in Berkeley, California.
This is sample text data for Algodata Infosystems, publisher 1389 in the pubs database. Algodata Infosystems is located in Berkeley, California.
This is sample text data for Algodata Infosystems, publisher 1389 in the pubs database. Algodata Infosystems is located in Berkeley, California.
This is sample text data for Algodata Infosystems, publisher 1389 in the pubs database. Algodata Infosystems is located in Berkeley, California.
This is sample text data for Algodata Infosystems, publisher 1389 in the pubs database. Algodata Infosystems is located in Berkeley, California.
This is sample text data for Algodata Infosystems, publisher 1389 in the pubs database. Algodata Infosystems is located in Berkeley, California.
This is sample text data for Algodata Infosystems, publisher 1389 in the pubs database. Algodata Infosystems is located in Berkeley, California.', 3)
INSERT [pub_info] ([logo], [pr_info], [pubID]) VALUES (0x474946383961F5003400B30F00000000800000008000808000000080800080008080808080C0C0C0FF000000FF00FFFF000000FFFF00FF00FFFFFFFFFF21F9040100000F002C00000000F50034004004FFF0C949ABBD38EBCDBBFF60288E64D90166AA016CEBBEB02ACF746D67E82DC2ACEEFFC0A02997B31027C521EF25698D8E42230E049D3E8AD8537385BC4179DB6B574C26637BE58BF38A1EB393DF2CE55CA52731F77918BE9FAFCD6180817F697F5F6E6C7A836D62876A817A79898A7E31524D708E7299159C9456929F9044777C6575A563A68E827D9D4C8D334BB3B051B6B7B83A8490B91EB4B3BDC1C251A1C24BC3C8C9C8C5C4BFCCCAD0D135ACC36B2E3BBCB655AD1CDB8F6921DEB8D48AA9ADA46046D7E0DC829B9D98E9988878D9AAE5AEF875BC6DEFF7E7A35C9943F18CCA3175C0A4295C48625F3B8610234A0C17D159C289189515CC7531A3C7891BFF9B59FA4812634820F24AAA94882EA50D8BBB3E8813598B8A3D7C0D6F12CB8710E5BA7536D9ED3C458F8B509CF17CE94CEA658F254D944889528306E83C245089629DDA4F8BD65885049ACBB7ADAB2A5364AFDAF344902752409A6085FA39105EBB3C2DAB2E52FA8611B7ACFA060956CB1370598176DB3E74FB956CCCA77207BB6B8CAAAADEA3FFBE01A48CD871D65569C37E25A458C5C9572E57AADE59F7F40A98B456CB36560F730967B3737B74ADBBB7EFDABF830BE70B11F6C8E1C82F31345E33B9F3A5C698FB7D4E9D779083D4B313D7985ABB77E0C9B07F1F0F3EFA71F2E8ED56EB98BEBD7559306FC72C6995EA7499F3B5DDA403FF17538AB6FD20C9FF7D463D531681971888E0104E45069D7C742D58DB7B29B45454811B381420635135B5D838D6E487612F876D98D984B73D2820877DFD871523F5E161D97DD7FCB4C82E31BEC8176856D9D8487D95E1E5D711401AE2448EF11074E47E9D69359382E8A8871391880C28E5861636399950FEFCA55E315D8279255C2C6AA89899B68588961C5B82C366693359F1CA89ACACB959971D76F6E6607B6E410E9D57B1A9196A52BDD56636CC08BA519C5E1EDA8743688906DA9D53F2E367999656A96292E2781397A6264E62A04E25FE49A59354696958409B11F527639DEAC84E7795553A9AACA85C68E8977D2A7919A5A7F83329A46F0D79698BF60D98688CCC118A6C3F8F38E6D89C8C12F635E49145F6132D69DCCE684725FC0546C3B40875D79E70A5867A8274E69E8BAEAC1FEEC02E92EE3AA7ADA015365BEFBE83F2EB6F351100003B, N'This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.
This is sample text data for Five Lakes Publishing, publisher 1622 in the pubs database. Five Lakes Publishing is located in Chicago, Illinois.', 4)
INSERT [pub_info] ([logo], [pr_info], [pubID]) VALUES (0x474946383961E3002500B30F00000000800000008000808000000080800080008080808080C0C0C0FF000000FF00FFFF000000FFFF00FF00FFFFFFFFFF21F9040100000F002C00000000E30025004004FFF0C949ABBD38EBCDBBFF60288E240858E705A4D2EA4E6E0CC7324DD1EB9CDBBAFCE1AC878DE7ABBD84476452C963369F2F288E933A595B404DB27834E67A5FEC37ACEC517D4EB24E5C8D069966361A5E8ED3C3DCA5AA54B9B2AE2D423082817F848286898386858754887B8A8D939094947E918B7D8780959E9D817C18986FA2A6A75A7B22A59B378E1DACAEB18F1940B6A8B8A853727AB5BD4E76676A37BFB9AF2A564D6BC0776E635BCE6DCFD2C3C873716879D4746C6053DA76E0DAB3A133D6D5B290929F9CEAEDEB6FA0C435EF9E97F59896EC28EEFA9DFF69A21C1BB4CA1E3E63084DB42B970FD6407D05C9E59298B0A2C58B18337AA0E88DA3468DC3FFD0692187A7982F5F2271B152162DE54795CEB0F0DAF8EBDA2A932F1FF203B38C484B6ED07674194ACD639679424B4EDB36279B4D3852FE1095266743955138C5209ADA6D5CB26DCDFC644DD351EACF804BCD32421A562DB6965F25AADD11B056BD7BA436C903E82A1D4A3D024769BAE777B0BB7887F51A0E022E9589BCFCE0DD6527597223C4917502ACBCF8D5E6C49F0B6FA60751A7C2748A3EE7DD6B70B5628F9A5873C6DB5936E57EB843C726043B95EBDE394F3584EC7096ED8DA60D86001EBCB9F3E72F99439F0E7DEC7297BA84D9924EFDB11A65566B8EFB510C7CC258DBB7779F7834A9756E6C97D114F95E5429F13CE5F7F9AAF51C996928604710FF544AFDC79717C10CD85157C6EDD75F7EB49C81D45C5EA9674E5BBBA065941BFB45F3D62D5E99E11488516568A15D1292255F635E8045E0520F3E15A0798DB5C5A08105EE52E3884C05255778E6F5C4A287CCB4D84D1D41CE08CD913C56656482EAEDE8E38D71B974553C199EC324573C3669237C585588E52D1ACE049F85521648659556CD83445D27C9F4D68501CE580E31748ED4948C0E3E88959B257C87E39D0A8EC5D812559234996A9EE5B6E864FE31BA5262971DE40FA5B75D9A487A9A79975C6AB5DD06EA6CCA9DB94FA6A1568AD8A4C33DBA6A5995EE5450AC0AA24A9C6DBAE9F6883CB48976D0ABA8D90AA9A88D6246C2ABA3FE8A1B43CA229B9C58AFC11E071AB1D1BE366DB5C9AE85DCA48595466B83AC95C61DA60D1146EEB3BB817ADA40A08CFBDBB2EB9972EB6EDB66D26D71768D5B2B1FEFC65B11AFA5FA96C93AF50AA6AFBEFE263C1DC0FCA2AB8AC210472C310A1100003B, N'This is sample text data for Ramona Publishers, publisher 1756 in the pubs database. Ramona Publishers is located in Dallas, Texas.', 5)
INSERT [pub_info] ([logo], [pr_info], [pubID]) VALUES (0x4749463839615D002200B30F00000000800000008000808000000080800080008080808080C0C0C0FF000000FF00FFFF000000FFFF00FF00FFFFFFFFFF21F9040100000F002C000000005D0022004004FFF0C949ABBD38EBCDFB03DF078C249895A386AA68BB9E6E0ACE623ABD1BC9E9985DFFB89E8E366BED782C5332563ABA4245A6744AAD5AAF4D2276CBED5EA1D026C528B230CD38B2C92721D78CC4772526748F9F611EB28DE7AFE25E818283604A1E8788898A7385838E8F55856F6C2C1D86392F6B9730708D6C5477673758A3865E92627E94754E173697A6A975809368949BB2AE7B9A6865AA734F80A2A17DA576AA5BB667C290CDCE4379CFD2CE9ED3D6A7CCD7DAA4D9C79341C8B9DF5FC052A8DEBA9BB696767B9C7FD5B8BBF23EABB9706BCAE5F05AB7E6C4C7488DDAF7251BC062530EFE93638C5B3580ECD4951312C217C425E73E89D38709D79D810D393BD20A528CE0AA704AA2D4D3082E583C89BD2C2D720753E1C8922697D44CF6AE53BF6D4041750B4AD467C54548932A1D7374A9D3A789004400003B, N'This is sample text data for GGG&G, publisher 9901 in the pubs database. GGG&G is located in München, Germany.', 6)
INSERT [pub_info] ([logo], [pr_info], [pubID]) VALUES (0x47494638396107012800B30F00000000800000008000808000000080800080008080808080C0C0C0FF000000FF00FFFF000000FFFF00FF00FFFFFFFFFF21F9040100000F002C00000000070128004004FFF0C949ABBD38EBCDBBFF60288E6469660005AC2C7BB56D05A7D24C4F339E3F765FC716980C3824F28418E4D1A552DA8ACCA5517A7B526F275912690D2A9BD11D14AB8B8257E7E9776BDEE452C2279C47A5CBEDEF2B3C3FBF9FC85981821D7D76868588878A898C8B838F1C8D928E733890829399949B979D9E9FA074A1A3A4A5A6A7458F583E69803F53AF4C62AD5E6DB13B6B3DAEAC6EBA64B365B26BB7ABBEB5C07FB428BCC4C8C1CCC7BBB065637C7A9B7BBE8CDADBDA8B7C31D9E1D88E2FA89E9AE9E49AE7EDA48DA2EEF2F3F4F597AEF6F9FAFBFC805D6CD28C0164C64D18BE3AAD88D87AA5C1DBC07FD59CE54293F0E0882AC39ED9CA2886E3308FB3FF262EBC726D591823204F2E0C09A4A3B32CFEACBC24198D86C48FD3E208D43832E3C0671A2D89737167281AA333219AC048D061499A3C83BEC8090BD84E5A99DE808B730DE9516B727CE85AE7C122BF73EAD29255CB76ADDBB6EC549C8504F7AD5DB37343A98D97576EDDBF7CFB0AEE8457EF5D4E83132BAEB1B8B1E3C749204B9EACB830E5CB984DE1F339A4E1CC88C93CB7D989D72234D1D3A672FEF85055C483C80A06742ADB664F3563119E417D5A8F52DFB1512AEC5D82E9C8662A477FB19A72B6F2E714413F8D0654AA75A8C4C648FDBC346ACDCD5487AFC439BE8BC8E8AA7F6BD77D2B7DF4E6C5882E57DFBDE2F56AEE6D87DFB8BFE06BE7E8F1C6CBCE4D2DC15751803C5956567EFA1D47A041E5F1176183CC1D571D21C2850396565CF5B1D5571D8AC21D08E099A15E85269E87207B1736B31E6FE620324E582116F5215178C86763518A9068DF7FE8C9C6207DCD0104A47B6B717388901EFA27238E3482454E43BB61E8D388F7FD44DD32473E79D43A527633232561E6F86536660256891699D175989A6F1A020A9C75C9D5E68274C619D79D91B5C5189F7906CA67297129D88F9E881A3AA83E8AB623E85E8B0EDAE89C892216E9A584B80318A69C7E3269A7A046FA69A8A4B6094004003B, N'This is sample text data for Scootney Books, publisher 9952 in the pubs database. Scootney Books is located in New York City, New York.', 7)
INSERT [pub_info] ([logo], [pr_info], [pubID]) VALUES (0x474946383961A9002400B30F00000000800000008000808000000080800080008080808080C0C0C0FF000000FF00FFFF000000FFFF00FF00FFFFFFFFFF21F9040100000F002C00000000A90024004004FFF0C949ABBD38EBCDBBFF60F8011A609E67653EA8D48A702CCFF44566689ED67CEFFF23D58E7513B686444A6EA26B126FC8E74AC82421A7ABE5F4594D61B7BBF0D6F562719A68A07ACDC6389925749AFC6EDBEFBCA24D3E96E2FF803D7A1672468131736E494A8B5C848D8633834B916E598B657E4A83905F7D9B7B56986064A09BA2A68D63603A2E717C9487B2B3209CA7AD52594751B4BD80B65D75B799BEC5BFAF7CC6CACB6638852ACC409F901BD33EB6BCCDC1D1CEA9967B23C082C3709662A69FA4A591E7AE84D87A5FA0AB502F43AC5D74EB9367B0624593FA5CB101ED144173E5F4315AE8485B4287FCBE39E446B1624173FEAC59DC2809594623D9C3388A54E4ACD59C642353E2F098E919319530DD61C405C7CBCB9831C5E5A2192C244E983A3FFE1CDA21282CA248ABB18C25336952A389D689E489B0D24483243B66CD8775A315801AA5A60A6B2DAC074E3741D6BBA8902BA687E9A6D1A3B6D6D15C7460C77AA3E3E556D79EBAF4AAAAB2CFCF578671DFDE657598305D51F7BE5E5A25361ED3388EED0A84B2B7535D6072C1D62DB5588BE5CCA5B1BDA377B99E3CBE9EDA31944A951ADF7DB15263A1429B37BB7E429D8EC4D754B87164078F2B87012002003B, N'This is sample text data for Lucerne Publishing, publisher 9999 in the pubs database. Lucerne publishing is located in Paris, France.
This is sample text data for Lucerne Publishing, publisher 9999 in the pubs database. Lucerne publishing is located in Paris, France.
This is sample text data for Lucerne Publishing, publisher 9999 in the pubs database. Lucerne publishing is located in Paris, France.
This is sample text data for Lucerne Publishing, publisher 9999 in the pubs database. Lucerne publishing is located in Paris, France.', 8)
SET IDENTITY_INSERT [publishers] ON 

INSERT [publishers] ([pub_name], [city], [state], [country], [ID]) VALUES (N'New Moon Books', N'Boston', N'MA', N'USA', 1)
INSERT [publishers] ([pub_name], [city], [state], [country], [ID]) VALUES (N'Binnet & Hardley', N'Washington', N'DC', N'USA', 2)
INSERT [publishers] ([pub_name], [city], [state], [country], [ID]) VALUES (N'Algodata Infosystems', N'Berkeley', N'CA', N'USA', 3)
INSERT [publishers] ([pub_name], [city], [state], [country], [ID]) VALUES (N'Five Lakes Publishing', N'Chicago', N'IL', N'USA', 4)
INSERT [publishers] ([pub_name], [city], [state], [country], [ID]) VALUES (N'Ramona Publishers', N'Dallas', N'TX', N'USA', 5)
INSERT [publishers] ([pub_name], [city], [state], [country], [ID]) VALUES (N'GGG&G', N'Mnchen', NULL, N'Germany', 6)
INSERT [publishers] ([pub_name], [city], [state], [country], [ID]) VALUES (N'Scootney Books', N'New York', N'NY', N'USA', 7)
INSERT [publishers] ([pub_name], [city], [state], [country], [ID]) VALUES (N'Lucerne Publishing', N'Paris', NULL, N'France', 8)
SET IDENTITY_INSERT [publishers] OFF
SET IDENTITY_INSERT [sales] ON 

INSERT [sales] ([ord_num], [ord_date], [qty], [payterms], [titleID], [storID], [ID]) VALUES (N'6871', CAST(N'1994-09-14T00:00:00.000' AS DateTime), 5, N'Net 60', 15, 1, 1)
INSERT [sales] ([ord_num], [ord_date], [qty], [payterms], [titleID], [storID], [ID]) VALUES (N'423LL930', CAST(N'1994-09-14T00:00:00.000' AS DateTime), 10, N'ON invoice', 15, 6, 2)
INSERT [sales] ([ord_num], [ord_date], [qty], [payterms], [titleID], [storID], [ID]) VALUES (N'P723', CAST(N'1993-03-11T00:00:00.000' AS DateTime), 25, N'Net 30', 3, 6, 3)
INSERT [sales] ([ord_num], [ord_date], [qty], [payterms], [titleID], [storID], [ID]) VALUES (N'X999', CAST(N'1993-02-21T00:00:00.000' AS DateTime), 35, N'ON invoice', 18, 5, 4)
INSERT [sales] ([ord_num], [ord_date], [qty], [payterms], [titleID], [storID], [ID]) VALUES (N'QQ2299', CAST(N'1993-10-28T00:00:00.000' AS DateTime), 15, N'Net 60', 13, 5, 5)
INSERT [sales] ([ord_num], [ord_date], [qty], [payterms], [titleID], [storID], [ID]) VALUES (N'TQ456', CAST(N'1993-12-12T00:00:00.000' AS DateTime), 10, N'Net 60', 12, 5, 6)
INSERT [sales] ([ord_num], [ord_date], [qty], [payterms], [titleID], [storID], [ID]) VALUES (N'N914014', CAST(N'1994-09-14T00:00:00.000' AS DateTime), 25, N'Net 30', 16, 4, 7)
INSERT [sales] ([ord_num], [ord_date], [qty], [payterms], [titleID], [storID], [ID]) VALUES (N'423LL922', CAST(N'1994-09-14T00:00:00.000' AS DateTime), 15, N'ON invoice', 16, 6, 8)
INSERT [sales] ([ord_num], [ord_date], [qty], [payterms], [titleID], [storID], [ID]) VALUES (N'QA879.1', CAST(N'1993-05-22T00:00:00.000' AS DateTime), 30, N'Net 30', 1, 6, 9)
INSERT [sales] ([ord_num], [ord_date], [qty], [payterms], [titleID], [storID], [ID]) VALUES (N'A2976', CAST(N'1993-05-24T00:00:00.000' AS DateTime), 50, N'Net 30', 11, 2, 10)
INSERT [sales] ([ord_num], [ord_date], [qty], [payterms], [titleID], [storID], [ID]) VALUES (N'P3087a', CAST(N'1993-05-29T00:00:00.000' AS DateTime), 20, N'Net 60', 2, 4, 11)
INSERT [sales] ([ord_num], [ord_date], [qty], [payterms], [titleID], [storID], [ID]) VALUES (N'722a', CAST(N'1994-09-13T00:00:00.000' AS DateTime), 3, N'Net 60', 6, 1, 12)
INSERT [sales] ([ord_num], [ord_date], [qty], [payterms], [titleID], [storID], [ID]) VALUES (N'QA7442.3', CAST(N'1994-09-13T00:00:00.000' AS DateTime), 75, N'ON invoice', 6, 2, 13)
INSERT [sales] ([ord_num], [ord_date], [qty], [payterms], [titleID], [storID], [ID]) VALUES (N'D4482', CAST(N'1994-09-14T00:00:00.000' AS DateTime), 10, N'Net 60', 6, 3, 14)
INSERT [sales] ([ord_num], [ord_date], [qty], [payterms], [titleID], [storID], [ID]) VALUES (N'N914008', CAST(N'1994-09-14T00:00:00.000' AS DateTime), 20, N'Net 30', 6, 4, 15)
INSERT [sales] ([ord_num], [ord_date], [qty], [payterms], [titleID], [storID], [ID]) VALUES (N'P3087a', CAST(N'1993-05-29T00:00:00.000' AS DateTime), 25, N'Net 60', 7, 4, 16)
INSERT [sales] ([ord_num], [ord_date], [qty], [payterms], [titleID], [storID], [ID]) VALUES (N'P3087a', CAST(N'1993-05-29T00:00:00.000' AS DateTime), 15, N'Net 60', 10, 4, 17)
INSERT [sales] ([ord_num], [ord_date], [qty], [payterms], [titleID], [storID], [ID]) VALUES (N'P3087a', CAST(N'1993-05-29T00:00:00.000' AS DateTime), 25, N'Net 60', 4, 4, 18)
INSERT [sales] ([ord_num], [ord_date], [qty], [payterms], [titleID], [storID], [ID]) VALUES (N'P2121', CAST(N'1992-06-15T00:00:00.000' AS DateTime), 40, N'Net 30', 9, 3, 19)
INSERT [sales] ([ord_num], [ord_date], [qty], [payterms], [titleID], [storID], [ID]) VALUES (N'P2121', CAST(N'1992-06-15T00:00:00.000' AS DateTime), 20, N'Net 30', 5, 3, 20)
INSERT [sales] ([ord_num], [ord_date], [qty], [payterms], [titleID], [storID], [ID]) VALUES (N'P2121', CAST(N'1992-06-15T00:00:00.000' AS DateTime), 20, N'Net 30', 14, 3, 21)
SET IDENTITY_INSERT [sales] OFF
SET IDENTITY_INSERT [stores] ON 

INSERT [stores] ([stor_name], [stor_address], [city], [state], [zip], [ID]) VALUES (N'Eric the Read Books', N'788 Catamaugus Ave.', N'Seattle', N'WA', N'98056', 1)
INSERT [stores] ([stor_name], [stor_address], [city], [state], [zip], [ID]) VALUES (N'Barnum''s', N'567 Pasadena Ave.', N'Tustin', N'CA', N'92789', 2)
INSERT [stores] ([stor_name], [stor_address], [city], [state], [zip], [ID]) VALUES (N'News & Brews', N'577 First St.', N'Los Gatos', N'CA', N'96745', 3)
INSERT [stores] ([stor_name], [stor_address], [city], [state], [zip], [ID]) VALUES (N'Doc-U-Mat: Quality Laundry and Books', N'24-A Avogadro Way', N'Remulade', N'WA', N'98014', 4)
INSERT [stores] ([stor_name], [stor_address], [city], [state], [zip], [ID]) VALUES (N'Fricative Bookshop', N'89 Madison St.', N'Fremont', N'CA', N'90019', 5)
INSERT [stores] ([stor_name], [stor_address], [city], [state], [zip], [ID]) VALUES (N'Bookbeat', N'679 Carson St.', N'Portland', N'OR', N'89076', 6)
SET IDENTITY_INSERT [stores] OFF
SET IDENTITY_INSERT [titleauthor] ON 

INSERT [titleauthor] ([au_ord], [royaltyper], [titleID], [ID], [personId]) VALUES (1, 100, 15, 1, 131)
INSERT [titleauthor] ([au_ord], [royaltyper], [titleID], [ID], [personId]) VALUES (2, 40, 15, 2, 116)
INSERT [titleauthor] ([au_ord], [royaltyper], [titleID], [ID], [personId]) VALUES (1, 100, 15, 3, 116)
INSERT [titleauthor] ([au_ord], [royaltyper], [titleID], [ID], [personId]) VALUES (1, 100, 15, 4, 112)
INSERT [titleauthor] ([au_ord], [royaltyper], [titleID], [ID], [personId]) VALUES (2, 40, 15, 5, 124)
INSERT [titleauthor] ([au_ord], [royaltyper], [titleID], [ID], [personId]) VALUES (2, 30, 15, 6, 124)
INSERT [titleauthor] ([au_ord], [royaltyper], [titleID], [ID], [personId]) VALUES (1, 100, 15, 7, 129)
INSERT [titleauthor] ([au_ord], [royaltyper], [titleID], [ID], [personId]) VALUES (1, 60, 15, 8, 110)
INSERT [titleauthor] ([au_ord], [royaltyper], [titleID], [ID], [personId]) VALUES (1, 50, 15, 9, 115)
INSERT [titleauthor] ([au_ord], [royaltyper], [titleID], [ID], [personId]) VALUES (3, 30, 15, 10, 118)
INSERT [titleauthor] ([au_ord], [royaltyper], [titleID], [ID], [personId]) VALUES (1, 100, 15, 11, 121)
INSERT [titleauthor] ([au_ord], [royaltyper], [titleID], [ID], [personId]) VALUES (1, 100, 15, 12, 121)
INSERT [titleauthor] ([au_ord], [royaltyper], [titleID], [ID], [personId]) VALUES (1, 100, 15, 13, 111)
INSERT [titleauthor] ([au_ord], [royaltyper], [titleID], [ID], [personId]) VALUES (1, 40, 15, 14, 132)
INSERT [titleauthor] ([au_ord], [royaltyper], [titleID], [ID], [personId]) VALUES (1, 100, 15, 15, 114)
INSERT [titleauthor] ([au_ord], [royaltyper], [titleID], [ID], [personId]) VALUES (1, 75, 15, 16, 113)
INSERT [titleauthor] ([au_ord], [royaltyper], [titleID], [ID], [personId]) VALUES (1, 60, 15, 17, 122)
INSERT [titleauthor] ([au_ord], [royaltyper], [titleID], [ID], [personId]) VALUES (2, 25, 15, 18, 122)
INSERT [titleauthor] ([au_ord], [royaltyper], [titleID], [ID], [personId]) VALUES (1, 75, 15, 19, 120)
INSERT [titleauthor] ([au_ord], [royaltyper], [titleID], [ID], [personId]) VALUES (1, 100, 15, 20, 125)
INSERT [titleauthor] ([au_ord], [royaltyper], [titleID], [ID], [personId]) VALUES (2, 50, 15, 21, 119)
INSERT [titleauthor] ([au_ord], [royaltyper], [titleID], [ID], [personId]) VALUES (2, 25, 15, 22, 127)
INSERT [titleauthor] ([au_ord], [royaltyper], [titleID], [ID], [personId]) VALUES (2, 50, 15, 23, 127)
INSERT [titleauthor] ([au_ord], [royaltyper], [titleID], [ID], [personId]) VALUES (1, 50, 15, 24, 126)
INSERT [titleauthor] ([au_ord], [royaltyper], [titleID], [ID], [personId]) VALUES (1, 100, 15, 25, 126)
SET IDENTITY_INSERT [titleauthor] OFF
SET IDENTITY_INSERT [titles] ON 

INSERT [titles] ([title], [titleType], [price], [advance], [royalty], [ytd_sales], [notes], [pubdate], [ID], [pubID]) VALUES (N'But Is It User Friendly?', N'popular_comp', 22.9500, 7000.0000, 16, 8780, N'A survey of software for the naive user, focusing on the ''friendliness'' of each.', CAST(N'1991-06-30T00:00:00.000' AS DateTime), 1, 3)
INSERT [titles] ([title], [titleType], [price], [advance], [royalty], [ytd_sales], [notes], [pubdate], [ID], [pubID]) VALUES (N'Computer Phobic AND Non-Phobic Individuals: Behavior Variations', N'psychology  ', 21.5900, 7000.0000, 10, 375, N'A must for the specialist, this book examines the difference between those who hate and fear computers and those who don''t.', CAST(N'1991-10-21T00:00:00.000' AS DateTime), 2, 2)
INSERT [titles] ([title], [titleType], [price], [advance], [royalty], [ytd_sales], [notes], [pubdate], [ID], [pubID]) VALUES (N'Cooking with Computers: Surreptitious Balance Sheets', N'business    ', 11.9500, 5000.0000, 10, 3876, N'Helpful hints on how to use your electronic resources to the best advantage.', CAST(N'1991-06-09T00:00:00.000' AS DateTime), 3, 3)
INSERT [titles] ([title], [titleType], [price], [advance], [royalty], [ytd_sales], [notes], [pubdate], [ID], [pubID]) VALUES (N'Emotional Security: A New Algorithm', N'psychology  ', 7.9900, 4000.0000, 10, 3336, N'Protecting yourself and your loved ones from undue emotional stress in the modern world. Use of computer and nutritional aids emphasized.', CAST(N'1991-06-12T00:00:00.000' AS DateTime), 4, 1)
INSERT [titles] ([title], [titleType], [price], [advance], [royalty], [ytd_sales], [notes], [pubdate], [ID], [pubID]) VALUES (N'Fifty Years in Buckingham Palace Kitchens', N'trad_cook   ', 11.9500, 4000.0000, 14, 15096, N'More anecdotes from the Queen''s favorite cook describing life among English royalty. Recipes, techniques, tender vignettes.', CAST(N'1991-06-12T00:00:00.000' AS DateTime), 5, 2)
INSERT [titles] ([title], [titleType], [price], [advance], [royalty], [ytd_sales], [notes], [pubdate], [ID], [pubID]) VALUES (N'Is Anger the Enemy?', N'psychology  ', 10.9500, 2275.0000, 12, 2045, N'Carefully researched study of the effects of strong emotions on the body. Metabolic charts included.', CAST(N'1991-06-15T00:00:00.000' AS DateTime), 6, 1)
INSERT [titles] ([title], [titleType], [price], [advance], [royalty], [ytd_sales], [notes], [pubdate], [ID], [pubID]) VALUES (N'Life Without Fear', N'psychology  ', 7.0000, 6000.0000, 10, 111, N'New exercise, meditation, and nutritional techniques that can reduce the shock of daily interactions. Popular audience. Sample menus included, exercise video available separately.', CAST(N'1991-10-05T00:00:00.000' AS DateTime), 7, 1)
INSERT [titles] ([title], [titleType], [price], [advance], [royalty], [ytd_sales], [notes], [pubdate], [ID], [pubID]) VALUES (N'Net Etiquette', N'popular_comp', NULL, NULL, NULL, NULL, N'A must-read for computer conferencing.', CAST(N'2019-08-27T15:58:18.170' AS DateTime), 8, 3)
INSERT [titles] ([title], [titleType], [price], [advance], [royalty], [ytd_sales], [notes], [pubdate], [ID], [pubID]) VALUES (N'Onions, Leeks, and Garlic: Cooking Secrets of the Mediterranean', N'trad_cook   ', 20.9500, 7000.0000, 10, 375, N'Profusely illustrated in color, this makes a wonderful gift book for a cuisine-oriented friend.', CAST(N'1991-10-21T00:00:00.000' AS DateTime), 9, 2)
INSERT [titles] ([title], [titleType], [price], [advance], [royalty], [ytd_sales], [notes], [pubdate], [ID], [pubID]) VALUES (N'Prolonged Data Deprivation: Four Case Studies', N'psychology  ', 19.9900, 2000.0000, 10, 4072, N'What happens when the data runs dry?  Searching evaluations of information-shortage effects.', CAST(N'1991-06-12T00:00:00.000' AS DateTime), 10, 1)
INSERT [titles] ([title], [titleType], [price], [advance], [royalty], [ytd_sales], [notes], [pubdate], [ID], [pubID]) VALUES (N'Secrets of Silicon Valley', N'popular_comp', 20.0000, 8000.0000, 10, 4095, N'Muckraking reporting on the world''s largest computer hardware and software manufacturers.', CAST(N'1994-06-12T00:00:00.000' AS DateTime), 11, 3)
INSERT [titles] ([title], [titleType], [price], [advance], [royalty], [ytd_sales], [notes], [pubdate], [ID], [pubID]) VALUES (N'Silicon Valley Gastronomic Treats', N'mod_cook    ', 19.9900, 0.0000, 12, 2032, N'Favorite recipes for quick, easy, and elegant meals.', CAST(N'1991-06-09T00:00:00.000' AS DateTime), 12, 2)
INSERT [titles] ([title], [titleType], [price], [advance], [royalty], [ytd_sales], [notes], [pubdate], [ID], [pubID]) VALUES (N'Straight Talk About Computers', N'business    ', 19.9900, 5000.0000, 10, 4095, N'Annotated analysis of what computers can do for you: a no-hype guide for the critical user.', CAST(N'1991-06-22T00:00:00.000' AS DateTime), 13, 3)
INSERT [titles] ([title], [titleType], [price], [advance], [royalty], [ytd_sales], [notes], [pubdate], [ID], [pubID]) VALUES (N'Sushi, Anyone?', N'trad_cook   ', 14.9900, 8000.0000, 10, 4095, N'Detailed instructions on how to make authentic Japanese sushi in your spare time.', CAST(N'1991-06-12T00:00:00.000' AS DateTime), 14, 2)
INSERT [titles] ([title], [titleType], [price], [advance], [royalty], [ytd_sales], [notes], [pubdate], [ID], [pubID]) VALUES (N'The Busy Executive''s Database Guide', N'business    ', 19.9900, 5000.0000, 10, 4095, N'An overview of available database systems with emphasis on common business applications. Illustrated.', CAST(N'1991-06-12T00:00:00.000' AS DateTime), 15, 3)
INSERT [titles] ([title], [titleType], [price], [advance], [royalty], [ytd_sales], [notes], [pubdate], [ID], [pubID]) VALUES (N'The Gourmet Microwave', N'mod_cook    ', 2.9900, 15000.0000, 24, 22246, N'Traditional French gourmet recipes adapted for modern microwave cooking.', CAST(N'1991-06-18T00:00:00.000' AS DateTime), 16, 2)
INSERT [titles] ([title], [titleType], [price], [advance], [royalty], [ytd_sales], [notes], [pubdate], [ID], [pubID]) VALUES (N'The Psychology of Computer Cooking', N'UNDECIDED   ', NULL, NULL, NULL, NULL, NULL, CAST(N'2019-08-27T15:58:18.170' AS DateTime), 17, 2)
INSERT [titles] ([title], [titleType], [price], [advance], [royalty], [ytd_sales], [notes], [pubdate], [ID], [pubID]) VALUES (N'You Can Combat Computer Stress!', N'business    ', 2.9900, 10125.0000, 24, 18722, N'The latest medical and psychological techniques for living with the electronic office. Easy-to-understand explanations.', CAST(N'1991-06-30T00:00:00.000' AS DateTime), 18, 1)
SET IDENTITY_INSERT [titles] OFF
ALTER TABLE [jobs] ADD  DEFAULT ('New Position - title not formalized yet') FOR [job_desc]
GO
ALTER TABLE [person_author] ADD  DEFAULT ('UNKNOWN') FOR [phone]
GO
ALTER TABLE [person_employee] ADD  DEFAULT ((1)) FOR [job_id]
GO
ALTER TABLE [person_employee] ADD  DEFAULT ((10)) FOR [job_lvl]
GO
ALTER TABLE [person_employee] ADD  DEFAULT (getdate()) FOR [hire_date]
GO
ALTER TABLE [publishers] ADD  DEFAULT ('USA') FOR [country]
GO
ALTER TABLE [titles] ADD  DEFAULT ('UNDECIDED') FOR [titleType]
GO
ALTER TABLE [titles] ADD  DEFAULT (getdate()) FOR [pubdate]
GO
ALTER TABLE [person_author]  WITH CHECK ADD  CONSTRAINT [FK_authors_person] FOREIGN KEY([ID])
REFERENCES [person] ([ID])
GO
ALTER TABLE [person_author] CHECK CONSTRAINT [FK_authors_person]
GO
ALTER TABLE [person_employee]  WITH CHECK ADD FOREIGN KEY([job_id])
REFERENCES [jobs] ([job_id])
GO
ALTER TABLE [person_employee]  WITH CHECK ADD  CONSTRAINT [FK_employee_person] FOREIGN KEY([ID])
REFERENCES [person] ([ID])
GO
ALTER TABLE [person_employee] CHECK CONSTRAINT [FK_employee_person]
GO
ALTER TABLE [person_employee]  WITH CHECK ADD  CONSTRAINT [FK_employee_publishers] FOREIGN KEY([pubID])
REFERENCES [publishers] ([ID])
GO
ALTER TABLE [person_employee] CHECK CONSTRAINT [FK_employee_publishers]
GO
ALTER TABLE [pub_info]  WITH CHECK ADD  CONSTRAINT [FK_pub_info_publishers] FOREIGN KEY([pubID])
REFERENCES [publishers] ([ID])
GO
ALTER TABLE [pub_info] CHECK CONSTRAINT [FK_pub_info_publishers]
GO
ALTER TABLE [sales]  WITH CHECK ADD  CONSTRAINT [FK_sales_stores] FOREIGN KEY([storID])
REFERENCES [stores] ([ID])
GO
ALTER TABLE [sales] CHECK CONSTRAINT [FK_sales_stores]
GO
ALTER TABLE [sales]  WITH CHECK ADD  CONSTRAINT [FK_sales_titles] FOREIGN KEY([titleID])
REFERENCES [titles] ([ID])
GO
ALTER TABLE [sales] CHECK CONSTRAINT [FK_sales_titles]
GO
ALTER TABLE [titleauthor]  WITH CHECK ADD  CONSTRAINT [FK_titleauthor_authors] FOREIGN KEY([personId])
REFERENCES [person_author] ([ID])
GO
ALTER TABLE [titleauthor] CHECK CONSTRAINT [FK_titleauthor_authors]
GO
ALTER TABLE [titleauthor]  WITH CHECK ADD  CONSTRAINT [FK_titleauthor_titles] FOREIGN KEY([titleID])
REFERENCES [titles] ([ID])
GO
ALTER TABLE [titleauthor] CHECK CONSTRAINT [FK_titleauthor_titles]
GO
ALTER TABLE [titles]  WITH CHECK ADD  CONSTRAINT [FK_titles_publishers] FOREIGN KEY([pubID])
REFERENCES [publishers] ([ID])
GO
ALTER TABLE [titles] CHECK CONSTRAINT [FK_titles_publishers]
GO
ALTER TABLE [jobs]  WITH CHECK ADD CHECK  (([max_lvl]<=(250)))
GO
ALTER TABLE [jobs]  WITH CHECK ADD CHECK  (([min_lvl]>=(10)))
GO
ALTER TABLE [person_author]  WITH CHECK ADD CHECK  (([zip] like '[0-9][0-9][0-9][0-9][0-9]'))
GO
