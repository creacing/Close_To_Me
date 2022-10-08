import avator from './../public/images/avator.jpg'
const author = 'Cheshire Cat'
const config = {
    //作者名字
    author,
    title: '柴郡猫',
    description: 'Wonderland',
    // 导航栏
    nav: [
        { name: author, link: "/", children: [], liClass: 'title', rel: 'start', iClass: '', aClass: '' },
        { name: '首页', link: "/", children: [], liClass: 'active', rel: 'section', iClass: 'i-home', aClass: '' },

        {
            name: '文章', link: "#", children: [
                { name: '归档', link: "/archives/", children: [], liClass: '', rel: 'section', iClass: 'i-list-alt', aClass: '' },
                // { name: '分类', link: "/categories", children: [], liClass: '', rel: 'section', iClass: 'i-th', aClass: '' },
                { name: '标签', link: "/tags", children: [], liClass: '', rel: 'section', iClass: 'i-tags', aClass: '' },
            ], liClass: 'dropdown', rel: '', iClass: 'i-feather', aClass: ''
        },
        { name: '收藏', link: "/WebSites/", children: [], liClass: '', rel: 'section', iClass: 'i-star', aClass: '' },
        // {
        //     name: '链环', link: "#", children: [
        //         // { name: '友達', link: "/friends/", children: [], liClass: '', rel: 'section', iClass: 'i-heart', aClass: '' },
        //         { name: '网址', link: "/WebSites/", children: [], liClass: '', rel: 'section', iClass: 'i-star', aClass: '' },
        //     ], liClass: 'dropdown', rel: '', iClass: 'i-magic', aClass: ''
        // },
        // { name: '关于', link: "/about/", 
        // children: [
        //   { name: '自设', link: "/about/qy", children: [], liClass: '', rel: 'section', iClass: 'i-cloud' }
        // ], liClass: 'dropdown', rel: 'section', iClass: 'i-user', aClass: '' },
        { name: '关于', link: "/about/", children: [], liClass: '', rel: 'section', iClass: 'i-cloud', aClass: '' },
        // { name: '开往', link: "#", children: [], liClass: '', rel: 'noopener external nofollow noreferrer', iClass: 'i-paper-plane', aClass: 'exturl' }
        { name: 'Github', link: "#", children: [], liClass: '', rel: 'noopener external nofollow noreferrer', iClass: 'i-paper-plane', aClass: 'exturl' }
    ],
    sideNav: [
        { name: '首页', link: "/", children: [], liClass: 'active', rel: 'section', iClass: 'i-home', aClass: '' },
        // i-feather
        { name: '归档', link: "/archives/", children: [], liClass: '', rel: 'section', iClass: 'i-list-alt', aClass: '' },
        { name: '标签', link: "/tags", children: [], liClass: '', rel: 'section', iClass: 'i-tags', aClass: '' },
        { name: '收藏', link: "/WebSites/", children: [], liClass: '', rel: 'section', iClass: 'i-star', aClass: '' },
        { name: '关于', link: "/about/", children: [], liClass: '', rel: 'section', iClass: 'i-cloud', aClass: '' },
        { name: 'Github', link: "#", children: [], liClass: '', rel: 'noopener external nofollow noreferrer', iClass: 'i-paper-plane', aClass: 'exturl' }
    ],
    sidebar: {
        avator,
        author: author,
        description: '一个专注于前端的web爱好者',
        articlesNum: '0',
        categoriesNum: '0',
        tagsNum: '33',
        socialLinks: [
            { url: 'https://github.com/', name: 'github', icon: "i-github" },
            { url: 'https://twitter.com/', name: 'twitter', icon: "i-twitter" },
            { url: 'https://www.zhihu.com/people/', name: 'zhihu', icon: "i-zhihu" },
            { url: 'https://music.163.com/', name: 'music', icon: "i-cloud-music" },
            { url: 'https://t.me/', name: 'telegram', icon: "i-paper-plane" },
            { url: '/about', name: 'about', icon: "i-address-card" },
        ]
    },
    //colud color
    cloudColorList: [
        '#747bff',
        '#646cff',
        '#cf9baa',
        '#de8293',
        '#5b93b1',
        '#1b5489',
        '#7690b8',
        '#cfd8e0',
        '#6896b7',
        '#db8ea6',
        '#7b9361',
        '#3b6f87',
        '#b85b6c',
        '#dd8a94',
        '#f38b61',
        '#ffa842',
        '#596085',
        '#3e3a64',
        '#e15195',
        '#5fa3d5',
        '#7c94b1',
        '#3e749f',
        '#da7b35',
        '#ff9d4e',
        '#345a6d',
    ]
}
export default config