/****** Object:  Table [dbo].[Teacher]    Script Date: 12/22/2009 10:16:55 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Teacher](
	[Teacher_ID] [int] NOT NULL IDENTITY(1,1),
	[Name] [nvarchar](50) NULL,
	[Surname] [nvarchar](50) NULL,
	[Mentor_ID] [int] NULL,
 CONSTRAINT [PK_Teacher] PRIMARY KEY CLUSTERED 
(
	[Teacher_ID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Course]    Script Date: 12/22/2009 10:16:55 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Course](
	[Course_ID] [int] NOT NULL IDENTITY(1,1),
	[Name] [nvarchar](100) NULL,
 CONSTRAINT [PK_Course] PRIMARY KEY CLUSTERED 
(
	[Course_ID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Student]    Script Date: 12/22/2009 10:16:55 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Student](
	[Student_ID] [int] NOT NULL IDENTITY(1,1),
	[Name] [nvarchar](50) NULL,
	[Surname] [nvarchar](50) NULL,
 CONSTRAINT [PK_Student] PRIMARY KEY CLUSTERED 
(
	[Student_ID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Attendance]    Script Date: 12/22/2009 10:16:55 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Attendance](
    [Attendance_ID] [int] NOT NULL IDENTITY(1,1),
	[Student_ID] [int] NULL,
	[Lecture_ID] [int] NULL,
	[Attendance] [nchar](1) NULL,
	 CONSTRAINT [PK_Attendance] PRIMARY KEY CLUSTERED (
	[Attendance_ID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Grade]    Script Date: 12/22/2009 10:16:55 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Grade](
	[Examination_ID] [int] NULL,
	[Student_ID] [int] NULL,
	[Grading_teacher_ID] [int] NULL,
	[Grade] [int] NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Examination]    Script Date: 12/22/2009 10:16:55 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Examination](
	[Examination_ID] [int] NOT NULL IDENTITY(1,1),
	[Course_ID] [int] NULL,
	[Responsible_teacher_ID] [int] NULL,
	[Date] [datetime] NULL,
	[Description] [nvarchar](50) NULL,
 CONSTRAINT [PK_Examination] PRIMARY KEY CLUSTERED 
(
	[Examination_ID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Course_teacher]    Script Date: 12/22/2009 10:16:55 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Course_teacher](
	[ID] [int] NOT NULL IDENTITY(1,1),
	[Course_ID] [int] NULL,
	[Teacher_ID] [int] NULL,
	[Start_date] [datetime] NULL,
	[End_date] [datetime] NULL,
 CONSTRAINT [PK_Course_teacher] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Lecture]    Script Date: 12/22/2009 10:16:55 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Lecture](
	[Lecture_ID] [int] NOT NULL IDENTITY(1,1),
	[Room] [nchar](10) NULL,
	[Day] [datetime] NULL,
	[Time] [nchar](10) NULL,
	[Course_ID] [int] NULL,
	[Teacher_ID] [int] NULL,
 CONSTRAINT [PK_Lecture] PRIMARY KEY CLUSTERED 
(
	[Lecture_ID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Student_course]    Script Date: 12/22/2009 10:16:55 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Student_course](
	[ID] [int] NOT NULL IDENTITY(1,1),
	[Student_ID] [int] NULL,
	[Course_ID] [int] NULL,
 CONSTRAINT [PK_[Student_course] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  ForeignKey [FK_Attendance_Lecture]    Script Date: 12/22/2009 10:16:55 ******/
ALTER TABLE [dbo].[Attendance]  ADD  CONSTRAINT [FK_Attendance_Lecture] FOREIGN KEY([Lecture_ID])
REFERENCES [dbo].[Lecture] ([Lecture_ID]) ON DELETE CASCADE
GO
ALTER TABLE [dbo].[Attendance] CHECK CONSTRAINT [FK_Attendance_Lecture]
GO
/****** Object:  ForeignKey [FK_Attendance_Student]    Script Date: 12/22/2009 10:16:55 ******/
ALTER TABLE [dbo].[Attendance]   ADD  CONSTRAINT [FK_Attendance_Student] FOREIGN KEY([Student_ID])
REFERENCES [dbo].[Student] ([Student_ID]) ON DELETE CASCADE
GO
ALTER TABLE [dbo].[Attendance] CHECK CONSTRAINT [FK_Attendance_Student]
GO
/****** Object:  ForeignKey [FK_Course_teacher_Course]    Script Date: 12/22/2009 10:16:55 ******/
ALTER TABLE [dbo].[Course_teacher]   ADD  CONSTRAINT [FK_Course_teacher_Course] FOREIGN KEY([Course_ID])
REFERENCES [dbo].[Course] ([Course_ID]) ON DELETE CASCADE
GO
ALTER TABLE [dbo].[Course_teacher] CHECK CONSTRAINT [FK_Course_teacher_Course]
GO
/****** Object:  ForeignKey [FK_Course_teacher_Teacher]    Script Date: 12/22/2009 10:16:55 ******/
ALTER TABLE [dbo].[Course_teacher]  ADD  CONSTRAINT [FK_Course_teacher_Teacher] FOREIGN KEY([Teacher_ID])
REFERENCES [dbo].[Teacher] ([Teacher_ID]) ON DELETE CASCADE
GO
ALTER TABLE [dbo].[Course_teacher] CHECK CONSTRAINT [FK_Course_teacher_Teacher]
GO
/****** Object:  ForeignKey [FK_Examination_Course]    Script Date: 12/22/2009 10:16:55 ******/
ALTER TABLE [dbo].[Examination]   ADD  CONSTRAINT [FK_Examination_Course] FOREIGN KEY([Course_ID])
REFERENCES [dbo].[Course] ([Course_ID]) ON DELETE CASCADE
GO
ALTER TABLE [dbo].[Examination] CHECK CONSTRAINT [FK_Examination_Course]
GO
/****** Object:  ForeignKey [FK_Examination_Teacher]    Script Date: 12/22/2009 10:16:55 ******/
ALTER TABLE [dbo].[Examination]   ADD  CONSTRAINT [FK_Examination_Teacher] FOREIGN KEY([Responsible_teacher_ID])
REFERENCES [dbo].[Teacher] ([Teacher_ID]) ON DELETE CASCADE
GO
ALTER TABLE [dbo].[Examination] CHECK CONSTRAINT [FK_Examination_Teacher]
GO
/****** Object:  ForeignKey [FK_Grade_Examination]    Script Date: 12/22/2009 10:16:55 ******/
ALTER TABLE [dbo].[Grade]   ADD  CONSTRAINT [FK_Grade_Examination] FOREIGN KEY([Examination_ID])
REFERENCES [dbo].[Examination] ([Examination_ID]) ON DELETE CASCADE
GO
ALTER TABLE [dbo].[Grade] CHECK CONSTRAINT [FK_Grade_Examination]
GO
/****** Object:  ForeignKey [FK_Grade_Student]    Script Date: 12/22/2009 10:16:55 ******/
ALTER TABLE [dbo].[Grade]  ADD  CONSTRAINT [FK_Grade_Student] FOREIGN KEY([Student_ID])
REFERENCES [dbo].[Student] ([Student_ID]) ON DELETE CASCADE
GO
ALTER TABLE [dbo].[Grade] CHECK CONSTRAINT [FK_Grade_Student]
GO
/****** Object:  ForeignKey [FK_Grade_Teacher]    Script Date: 12/22/2009 10:16:55 ******/
ALTER TABLE [dbo].[Grade]  WITH CHECK ADD  CONSTRAINT [FK_Grade_Teacher] FOREIGN KEY([Grading_teacher_ID])
REFERENCES [dbo].[Teacher] ([Teacher_ID])
GO
ALTER TABLE [dbo].[Grade] CHECK CONSTRAINT [FK_Grade_Teacher]
GO
/****** Object:  ForeignKey [FK_Lecture_Course]    Script Date: 12/22/2009 10:16:55 ******/
ALTER TABLE [dbo].[Lecture]   ADD  CONSTRAINT [FK_Lecture_Course] FOREIGN KEY([Course_ID])
REFERENCES [dbo].[Course] ([Course_ID]) ON DELETE CASCADE
GO
ALTER TABLE [dbo].[Lecture] CHECK CONSTRAINT [FK_Lecture_Course]
GO
/****** Object:  ForeignKey [FK_Lecture_Teacher]    Script Date: 12/22/2009 10:16:55 ******/
ALTER TABLE [dbo].[Lecture]   ADD  CONSTRAINT [FK_Lecture_Teacher] FOREIGN KEY([Teacher_ID])
REFERENCES [dbo].[Teacher] ([Teacher_ID]) ON DELETE CASCADE
GO
ALTER TABLE [dbo].[Lecture] CHECK CONSTRAINT [FK_Lecture_Teacher]
GO
/****** Object:  ForeignKey [FK_Student_course_Course]    Script Date: 12/22/2009 10:16:55 ******/
ALTER TABLE [dbo].[Student_course]  ADD  CONSTRAINT [FK_Student_course_Course] FOREIGN KEY([Course_ID])
REFERENCES [dbo].[Course] ([Course_ID]) ON DELETE CASCADE
GO
ALTER TABLE [dbo].[Student_course] CHECK CONSTRAINT [FK_Student_course_Course]
GO
/****** Object:  ForeignKey [FK_Student_course_Student]    Script Date: 12/22/2009 10:16:55 ******/
ALTER TABLE [dbo].[Student_course]   ADD  CONSTRAINT [FK_Student_course_Student] FOREIGN KEY([Student_ID])
REFERENCES [dbo].[Student] ([Student_ID]) ON DELETE CASCADE
GO
ALTER TABLE [dbo].[Student_course] CHECK CONSTRAINT [FK_Student_course_Student]
GO
/****** Object:  ForeignKey [FK_Teacher_Teacher]    Script Date: 12/22/2009 10:16:55 ******/
ALTER TABLE [dbo].[Teacher] WITH CHECK  ADD  CONSTRAINT [FK_Teacher_Teacher] FOREIGN KEY([Mentor_ID])
REFERENCES [dbo].[Teacher] ([Teacher_ID]) 
GO
ALTER TABLE [dbo].[Teacher] CHECK CONSTRAINT [FK_Teacher_Teacher]
GO

