
/****** Object:  Table [dbo].[author]    Script Date: 29/10/2019 17:27:25 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[author](
	[phone] [char](12) NOT NULL,
	[address] [varchar](40) NULL,
	[city] [varchar](20) NULL,
	[state] [char](2) NULL,
	[zip] [char](5) NULL,
	[contract] [bit] NOT NULL,
	[ID] [int] NOT NULL,
	[fname] [varchar](20) NULL,
	[lname] [varchar](40) NULL,
 CONSTRAINT [PK_authors] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[publishers]    Script Date: 29/10/2019 17:27:25 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[publishers](
	[pub_name] [varchar](40) NULL,
	[city] [varchar](20) NULL,
	[country] [varchar](30) NULL,
	[ID] [int] IDENTITY(1,1) NOT NULL,
 CONSTRAINT [PK_publishers] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[titleauthor]    Script Date: 29/10/2019 17:27:25 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[titleauthor](
	[au_ord] [tinyint] NULL,
	[titleID] [int] NULL,
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[personId] [int] NULL,
 CONSTRAINT [PK_titleauthor] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[titles]    Script Date: 29/10/2019 17:27:25 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[titles](
	[title] [varchar](80) NOT NULL,
	[titleType] [char](12) NOT NULL,
	[price] [money] NULL,
	[pubdate] [datetime] NOT NULL,
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[pubID] [int] NULL,
 CONSTRAINT [PK_titles] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
INSERT [dbo].[author] ([phone], [address], [city], [state], [zip], [contract], [ID], [fname], [lname]) VALUES (N'415 658-9932', N'6223 Bateman St.', N'Berkeley', N'CA', N'94705', 1, 110, N'Abraham', N'Bennet')
INSERT [dbo].[author] ([phone], [address], [city], [state], [zip], [contract], [ID], [fname], [lname]) VALUES (N'503 745-6402', N'55 Hillsdale Bl.', N'Corvallis', N'OR', N'97330', 1, 111, N'Reginald', N'Blotchet-Halls')
INSERT [dbo].[author] ([phone], [address], [city], [state], [zip], [contract], [ID], [fname], [lname]) VALUES (N'415 548-7723', N'589 Darwin Ln.', N'Berkeley', N'CA', N'94705', 1, 112, N'Cheryl', N'Carson')
INSERT [dbo].[author] ([phone], [address], [city], [state], [zip], [contract], [ID], [fname], [lname]) VALUES (N'219 547-9982', N'3 Balding Pl.', N'Gary', N'IN', N'46403', 1, 113, N'Michel', N'DeFrance')
INSERT [dbo].[author] ([phone], [address], [city], [state], [zip], [contract], [ID], [fname], [lname]) VALUES (N'615 996-8275', N'2286 Cram Pl. #86', N'Ann Arbor', N'MI', N'48105', 1, 114, N'Innes', N'del Castillo')
INSERT [dbo].[author] ([phone], [address], [city], [state], [zip], [contract], [ID], [fname], [lname]) VALUES (N'415 836-7128', N'3410 Blonde St.', N'Palo Alto', N'CA', N'94301', 1, 115, N'Ann', N'Dull')
INSERT [dbo].[author] ([phone], [address], [city], [state], [zip], [contract], [ID], [fname], [lname]) VALUES (N'415 986-7020', N'309 63rd St. #411', N'Oakland', N'CA', N'94618', 1, 116, N'Marjorie', N'Green')
INSERT [dbo].[author] ([phone], [address], [city], [state], [zip], [contract], [ID], [fname], [lname]) VALUES (N'615 297-2723', N'22 Graybar House Rd.', N'Nashville', N'TN', N'37215', 0, 117, N'Morningstar', N'Greene')
INSERT [dbo].[author] ([phone], [address], [city], [state], [zip], [contract], [ID], [fname], [lname]) VALUES (N'707 938-6445', N'PO Box 792', N'Covelo', N'CA', N'95428', 1, 118, N'Burt', N'Gringlesby')
INSERT [dbo].[author] ([phone], [address], [city], [state], [zip], [contract], [ID], [fname], [lname]) VALUES (N'415 836-7128', N'3410 Blonde St.', N'Palo Alto', N'CA', N'94301', 1, 119, N'Sheryl', N'Hunter')
INSERT [dbo].[author] ([phone], [address], [city], [state], [zip], [contract], [ID], [fname], [lname]) VALUES (N'415 534-9219', N'5720 McAuley St.', N'Oakland', N'CA', N'94609', 1, 120, N'Livia', N'Karsen')
INSERT [dbo].[author] ([phone], [address], [city], [state], [zip], [contract], [ID], [fname], [lname]) VALUES (N'415 585-4620', N'18 Broadway Av.', N'San Francisco', N'CA', N'94130', 1, 121, N'Charlene', N'Locksley')
INSERT [dbo].[author] ([phone], [address], [city], [state], [zip], [contract], [ID], [fname], [lname]) VALUES (N'415 354-7128', N'44 Upland Hts.', N'Oakland', N'CA', N'94612', 1, 122, N'Stearns', N'MacFeather')
INSERT [dbo].[author] ([phone], [address], [city], [state], [zip], [contract], [ID], [fname], [lname]) VALUES (N'707 448-4982', N'301 Putnam', N'Vacaville', N'CA', N'95688', 0, 123, N'Heather', N'McBadden')
INSERT [dbo].[author] ([phone], [address], [city], [state], [zip], [contract], [ID], [fname], [lname]) VALUES (N'408 286-2428', N'22 Cleveland Av. #14', N'San Jose', N'CA', N'95128', 1, 124, N'Michael', N'O''Leary')
INSERT [dbo].[author] ([phone], [address], [city], [state], [zip], [contract], [ID], [fname], [lname]) VALUES (N'301 946-8853', N'1956 Arlington Pl.', N'Rockville', N'MD', N'20853', 1, 125, N'Sylvia', N'Panteley')
INSERT [dbo].[author] ([phone], [address], [city], [state], [zip], [contract], [ID], [fname], [lname]) VALUES (N'801 826-0752', N'67 Seventh Av.', N'Salt Lake City', N'UT', N'84152', 1, 126, N'Albert', N'Ringer')
INSERT [dbo].[author] ([phone], [address], [city], [state], [zip], [contract], [ID], [fname], [lname]) VALUES (N'801 826-0752', N'67 Seventh Av.', N'Salt Lake City', N'UT', N'84152', 1, 127, N'Anne', N'Ringer')
INSERT [dbo].[author] ([phone], [address], [city], [state], [zip], [contract], [ID], [fname], [lname]) VALUES (N'913 843-0462', N'10 Mississippi Dr.', N'Lawrence', N'KS', N'66044', 0, 128, N'Meander', N'Smith')
INSERT [dbo].[author] ([phone], [address], [city], [state], [zip], [contract], [ID], [fname], [lname]) VALUES (N'415 834-2919', N'5420 College Av.', N'Oakland', N'CA', N'94609', 1, 129, N'Dean', N'Straight')
INSERT [dbo].[author] ([phone], [address], [city], [state], [zip], [contract], [ID], [fname], [lname]) VALUES (N'415 843-2991', N'5420 Telegraph Av.', N'Oakland', N'CA', N'94609', 0, 130, N'Dirk', N'Stringer')
INSERT [dbo].[author] ([phone], [address], [city], [state], [zip], [contract], [ID], [fname], [lname]) VALUES (N'408 496-7223', N'10932 Bigge Rd.', N'Menlo Park', N'CA', N'94025', 1, 131, N'Johnson', N'White')
INSERT [dbo].[author] ([phone], [address], [city], [state], [zip], [contract], [ID], [fname], [lname]) VALUES (N'415 935-4228', N'3 Silver Ct.', N'Walnut Creek', N'CA', N'94595', 1, 132, N'Akiko', N'Yokomoto')
SET IDENTITY_INSERT [dbo].[publishers] ON 

INSERT [dbo].[publishers] ([pub_name], [city], [country], [ID]) VALUES (N'New Moon Books', N'Boston', N'USA', 1)
INSERT [dbo].[publishers] ([pub_name], [city], [country], [ID]) VALUES (N'Binnet & Hardley', N'Washington', N'USA', 2)
INSERT [dbo].[publishers] ([pub_name], [city], [country], [ID]) VALUES (N'Algodata Infosystems', N'Berkeley', N'USA', 3)
INSERT [dbo].[publishers] ([pub_name], [city], [country], [ID]) VALUES (N'Five Lakes Publishing', N'Chicago', N'USA', 4)
INSERT [dbo].[publishers] ([pub_name], [city], [country], [ID]) VALUES (N'Ramona Publishers', N'Dallas', N'USA', 5)
INSERT [dbo].[publishers] ([pub_name], [city], [country], [ID]) VALUES (N'GGG&G', N'Mnchen', N'Germany', 6)
INSERT [dbo].[publishers] ([pub_name], [city], [country], [ID]) VALUES (N'Scootney Books', N'New York', N'USA', 7)
INSERT [dbo].[publishers] ([pub_name], [city], [country], [ID]) VALUES (N'Lucerne Publishing', N'Paris', N'France', 8)
SET IDENTITY_INSERT [dbo].[publishers] OFF
SET IDENTITY_INSERT [dbo].[titleauthor] ON 

INSERT [dbo].[titleauthor] ([au_ord], [titleID], [ID], [personId]) VALUES (1, 15, 1, 131)
INSERT [dbo].[titleauthor] ([au_ord], [titleID], [ID], [personId]) VALUES (2, 15, 2, 116)
INSERT [dbo].[titleauthor] ([au_ord], [titleID], [ID], [personId]) VALUES (1, 15, 3, 116)
INSERT [dbo].[titleauthor] ([au_ord], [titleID], [ID], [personId]) VALUES (1, 15, 4, 112)
INSERT [dbo].[titleauthor] ([au_ord], [titleID], [ID], [personId]) VALUES (2, 15, 5, 124)
INSERT [dbo].[titleauthor] ([au_ord], [titleID], [ID], [personId]) VALUES (2, 15, 6, 124)
INSERT [dbo].[titleauthor] ([au_ord], [titleID], [ID], [personId]) VALUES (1, 15, 7, 129)
INSERT [dbo].[titleauthor] ([au_ord], [titleID], [ID], [personId]) VALUES (1, 15, 8, 110)
INSERT [dbo].[titleauthor] ([au_ord], [titleID], [ID], [personId]) VALUES (1, 15, 9, 115)
INSERT [dbo].[titleauthor] ([au_ord], [titleID], [ID], [personId]) VALUES (3, 15, 10, 118)
INSERT [dbo].[titleauthor] ([au_ord], [titleID], [ID], [personId]) VALUES (1, 15, 11, 121)
INSERT [dbo].[titleauthor] ([au_ord], [titleID], [ID], [personId]) VALUES (1, 15, 12, 121)
INSERT [dbo].[titleauthor] ([au_ord], [titleID], [ID], [personId]) VALUES (1, 15, 13, 111)
INSERT [dbo].[titleauthor] ([au_ord], [titleID], [ID], [personId]) VALUES (1, 15, 14, 132)
INSERT [dbo].[titleauthor] ([au_ord], [titleID], [ID], [personId]) VALUES (1, 15, 15, 114)
INSERT [dbo].[titleauthor] ([au_ord], [titleID], [ID], [personId]) VALUES (1, 15, 16, 113)
INSERT [dbo].[titleauthor] ([au_ord], [titleID], [ID], [personId]) VALUES (1, 15, 17, 122)
INSERT [dbo].[titleauthor] ([au_ord], [titleID], [ID], [personId]) VALUES (2, 15, 18, 122)
INSERT [dbo].[titleauthor] ([au_ord], [titleID], [ID], [personId]) VALUES (1, 15, 19, 120)
INSERT [dbo].[titleauthor] ([au_ord], [titleID], [ID], [personId]) VALUES (1, 15, 20, 125)
INSERT [dbo].[titleauthor] ([au_ord], [titleID], [ID], [personId]) VALUES (2, 15, 21, 119)
INSERT [dbo].[titleauthor] ([au_ord], [titleID], [ID], [personId]) VALUES (2, 15, 22, 127)
INSERT [dbo].[titleauthor] ([au_ord], [titleID], [ID], [personId]) VALUES (2, 15, 23, 127)
INSERT [dbo].[titleauthor] ([au_ord], [titleID], [ID], [personId]) VALUES (1, 15, 24, 126)
INSERT [dbo].[titleauthor] ([au_ord], [titleID], [ID], [personId]) VALUES (1, 15, 25, 126)
SET IDENTITY_INSERT [dbo].[titleauthor] OFF
SET IDENTITY_INSERT [dbo].[titles] ON 

INSERT [dbo].[titles] ([title], [titleType], [price], [pubdate], [ID], [pubID]) VALUES (N'But Is It User Friendly?', N'popular_comp', 22.9500, CAST(N'1991-06-30T00:00:00.000' AS DateTime), 1, 3)
INSERT [dbo].[titles] ([title], [titleType], [price], [pubdate], [ID], [pubID]) VALUES (N'Computer Phobic AND Non-Phobic Individuals: Behavior Variations', N'psychology  ', 21.5900, CAST(N'1991-10-21T00:00:00.000' AS DateTime), 2, 2)
INSERT [dbo].[titles] ([title], [titleType], [price], [pubdate], [ID], [pubID]) VALUES (N'Cooking with Computers: Surreptitious Balance Sheets', N'business    ', 11.9500, CAST(N'1991-06-09T00:00:00.000' AS DateTime), 3, 3)
INSERT [dbo].[titles] ([title], [titleType], [price], [pubdate], [ID], [pubID]) VALUES (N'Emotional Security: A New Algorithm', N'psychology  ', 7.9900, CAST(N'1991-06-12T00:00:00.000' AS DateTime), 4, 1)
INSERT [dbo].[titles] ([title], [titleType], [price], [pubdate], [ID], [pubID]) VALUES (N'Fifty Years in Buckingham Palace Kitchens', N'trad_cook   ', 11.9500, CAST(N'1991-06-12T00:00:00.000' AS DateTime), 5, 2)
INSERT [dbo].[titles] ([title], [titleType], [price], [pubdate], [ID], [pubID]) VALUES (N'Is Anger the Enemy?', N'psychology  ', 10.9500, CAST(N'1991-06-15T00:00:00.000' AS DateTime), 6, 1)
INSERT [dbo].[titles] ([title], [titleType], [price], [pubdate], [ID], [pubID]) VALUES (N'Life Without Fear', N'psychology  ', 7.0000, CAST(N'1991-10-05T00:00:00.000' AS DateTime), 7, 1)
INSERT [dbo].[titles] ([title], [titleType], [price], [pubdate], [ID], [pubID]) VALUES (N'Net Etiquette', N'popular_comp', NULL, CAST(N'2019-08-27T15:58:18.170' AS DateTime), 8, 3)
INSERT [dbo].[titles] ([title], [titleType], [price], [pubdate], [ID], [pubID]) VALUES (N'Onions, Leeks, and Garlic: Cooking Secrets of the Mediterranean', N'trad_cook   ', 20.9500, CAST(N'1991-10-21T00:00:00.000' AS DateTime), 9, 2)
INSERT [dbo].[titles] ([title], [titleType], [price], [pubdate], [ID], [pubID]) VALUES (N'Prolonged Data Deprivation: Four Case Studies', N'psychology  ', 19.9900, CAST(N'1991-06-12T00:00:00.000' AS DateTime), 10, 1)
INSERT [dbo].[titles] ([title], [titleType], [price], [pubdate], [ID], [pubID]) VALUES (N'Secrets of Silicon Valley', N'popular_comp', 20.0000, CAST(N'1994-06-12T00:00:00.000' AS DateTime), 11, 3)
INSERT [dbo].[titles] ([title], [titleType], [price], [pubdate], [ID], [pubID]) VALUES (N'Silicon Valley Gastronomic Treats', N'mod_cook    ', 19.9900, CAST(N'1991-06-09T00:00:00.000' AS DateTime), 12, 2)
INSERT [dbo].[titles] ([title], [titleType], [price], [pubdate], [ID], [pubID]) VALUES (N'Straight Talk About Computers', N'business    ', 19.9900, CAST(N'1991-06-22T00:00:00.000' AS DateTime), 13, 3)
INSERT [dbo].[titles] ([title], [titleType], [price], [pubdate], [ID], [pubID]) VALUES (N'Sushi, Anyone?', N'trad_cook   ', 14.9900, CAST(N'1991-06-12T00:00:00.000' AS DateTime), 14, 2)
INSERT [dbo].[titles] ([title], [titleType], [price], [pubdate], [ID], [pubID]) VALUES (N'The Busy Executive''s Database Guide', N'business    ', 19.9900, CAST(N'1991-06-12T00:00:00.000' AS DateTime), 15, 3)
INSERT [dbo].[titles] ([title], [titleType], [price], [pubdate], [ID], [pubID]) VALUES (N'The Gourmet Microwave', N'mod_cook    ', 2.9900, CAST(N'1991-06-18T00:00:00.000' AS DateTime), 16, 2)
INSERT [dbo].[titles] ([title], [titleType], [price], [pubdate], [ID], [pubID]) VALUES (N'The Psychology of Computer Cooking', N'UNDECIDED   ', NULL, CAST(N'2019-08-27T15:58:18.170' AS DateTime), 17, 2)
INSERT [dbo].[titles] ([title], [titleType], [price], [pubdate], [ID], [pubID]) VALUES (N'You Can Combat Computer Stress!', N'business    ', 2.9900, CAST(N'1991-06-30T00:00:00.000' AS DateTime), 18, 1)
SET IDENTITY_INSERT [dbo].[titles] OFF
ALTER TABLE [dbo].[author] ADD  DEFAULT ('UNKNOWN') FOR [phone]
GO
ALTER TABLE [dbo].[publishers] ADD  DEFAULT ('USA') FOR [country]
GO
ALTER TABLE [dbo].[titles] ADD  DEFAULT ('UNDECIDED') FOR [titleType]
GO
ALTER TABLE [dbo].[titles] ADD  DEFAULT (getdate()) FOR [pubdate]
GO
ALTER TABLE [dbo].[titleauthor]  WITH CHECK ADD  CONSTRAINT [FK_titleauthor_authors] FOREIGN KEY([personId])
REFERENCES [dbo].[author] ([ID])
GO
ALTER TABLE [dbo].[titleauthor] CHECK CONSTRAINT [FK_titleauthor_authors]
GO
ALTER TABLE [dbo].[titleauthor]  WITH CHECK ADD  CONSTRAINT [FK_titleauthor_titles] FOREIGN KEY([titleID])
REFERENCES [dbo].[titles] ([ID])
GO
ALTER TABLE [dbo].[titleauthor] CHECK CONSTRAINT [FK_titleauthor_titles]
GO
ALTER TABLE [dbo].[titles]  WITH CHECK ADD  CONSTRAINT [FK_titles_publishers] FOREIGN KEY([pubID])
REFERENCES [dbo].[publishers] ([ID])
GO
ALTER TABLE [dbo].[titles] CHECK CONSTRAINT [FK_titles_publishers]
GO
ALTER TABLE [dbo].[author]  WITH CHECK ADD CHECK  (([zip] like '[0-9][0-9][0-9][0-9][0-9]'))
GO

