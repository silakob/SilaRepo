USE [SmartDevice]
GO
/****** Object:  Table [dbo].[Promotion]    Script Date: 18/11/2561 16:29:48 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Promotion](
	[PromotionKey] [int] IDENTITY(1,1) NOT NULL,
	[PromotionName] [varchar](200) NOT NULL,
	[IssueDate] [datetime] NULL,
	[ExpireDate] [datetime] NULL,
	[DiscountRate] [float] NULL,
	[DiscountPrice] [float] NULL,
	[Description] [varchar](512) NULL,
	[CreateDate] [datetime] NULL,
	[CreateBy] [int] NULL,
	[ModifyDate] [datetime] NULL,
	[ModifyBy] [int] NULL,
	[Active] [tinyint] NULL,
	[FileName] [varchar](200) NULL,
	[PhysicalPath] [varchar](200) NULL,
	[IISPath] [varchar](200) NULL,
 CONSTRAINT [PK_Promotion_1] PRIMARY KEY CLUSTERED 
(
	[PromotionKey] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[Users]    Script Date: 18/11/2561 16:29:48 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Users](
	[UserKey] [int] IDENTITY(1,1) NOT NULL,
	[UserName] [varchar](20) NOT NULL,
	[Password] [varchar](200) NOT NULL,
	[Email] [varchar](100) NULL,
	[PhoneNo] [varchar](15) NULL,
	[Address] [varchar](512) NULL,
	[UserType] [varchar](1) NULL,
	[CreateDate] [datetime] NULL,
	[ModifyDate] [datetime] NULL,
	[NameAndSurname] [varchar](200) NULL,
	[Active] [tinyint] NULL,
 CONSTRAINT [PK_Users] PRIMARY KEY CLUSTERED 
(
	[UserKey] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
ALTER TABLE [dbo].[Promotion]  WITH CHECK ADD  CONSTRAINT [FK_Promotion_Users] FOREIGN KEY([CreateBy])
REFERENCES [dbo].[Users] ([UserKey])
GO
ALTER TABLE [dbo].[Promotion] CHECK CONSTRAINT [FK_Promotion_Users]
GO
ALTER TABLE [dbo].[Promotion]  WITH CHECK ADD  CONSTRAINT [FK_Promotion_Users1] FOREIGN KEY([ModifyBy])
REFERENCES [dbo].[Users] ([UserKey])
GO
ALTER TABLE [dbo].[Promotion] CHECK CONSTRAINT [FK_Promotion_Users1]
GO
