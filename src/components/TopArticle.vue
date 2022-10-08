<template>
  <div class="segments sticky">
    <article class="item show">
      <div class="cover">
        <a :href="MOCKDATA.path" :title="MOCKDATA.title">
          <img :data-src="MOCKDATA.imgSrc" :src="MOCKDATA.imgSrc" class="lozaded" />
        </a>
      </div>
      <div class="info">
        <div class="meta">
          <span class="item" :title="MOCKDATA.createTime">
            <span class="icon">
              <i class="ic i-calendar"></i>
            </span>
            <time :datetime="MOCKDATA.dateTime">{{MOCKDATA.date}}</time>
          </span>
          <span class="item" title="本文字数">
            <span class="icon">
              <i class="ic i-pen"></i>
            </span>
            <span>{{MOCKDATA.fontNums}}</span>
            <span class="text">字</span>
          </span>
          <span class="item" title="阅读时长">
            <span class="icon">
              <i class="ic i-clock"></i>
            </span>
            <span>{{MOCKDATA.readTime}}</span>
          </span>
        </div>
        <h3>
          <a :href="MOCKDATA.path" :title="MOCKDATA.title">{{MOCKDATA.title}}</a>
        </h3>
        <div class="excerpt">{{MOCKDATA.description}}</div>
        <div class="meta footer">
          <span>
            <a :href="MOCKDATA.flagPath" :title="MOCKDATA.flag">
              <i class="ic i-flag"></i>
              {{MOCKDATA.flag}}
            </a>
          </span>
        </div>
        <a :href="MOCKDATA.path" :title="MOCKDATA.title" class="btn">more...</a>
      </div>
    </article>
  </div>
</template>

<script setup>
import MOCKDATA from '@/utils/MOCKDATA.js'
</script>
